#if defined(_WIN32) //Определение того что мы в Windows
#ifndef _WIN32_WINNT 
#define _WIN32_WINNT 0x0600 // Минимальная версия Windows - Vista
#endif
#include <winsock2.h> //Основная библиотека сокетов на windows
#include <ws2tcpip.h> //дополнительные функции windows типо getaddrinfo()
#pragma comment(lib, "ws2_32.lib") //Указание линковщику подключить Winsock
#else
#include <sys/types.h> // отвечает за системные типы данных
#include <sys/socket.h> // основные функции socket(accept, bind< listen)
#include <netinet/in.h> // определение для интенет протоколов
#include <arpa/inet.h> // функции для работы с ip адресами 
#include <netdb.h> // функии для работы с DNS
#include <unistd.h> // функции UNIX
#include <errno.h> // Содежит код поледней ошибки

#endif

//Определение макросов
#if defined(_WIN32)// для Windows 
#define ISVALIDSOCKET(s) ((s) != INVALID_SOCKET) // константа для проверки валидности сокета
#define CLOSESOCKET(s) closesocket(s) // константа для закрытия сокета 
#define GETSOCKETERRNO() (WSAGetLastError()) //Содержит последнюю ошибку 

#else //Для линукс
#define ISVALIDSOCKET(s) ((s) >= 0) // константа для проверки валидности сокета
#define CLOSESOCKET(s) close(s) // константа для закрытия сокета 
#define SOCKET int //Определяем тип SOCKET для того что бы он везде использоваляся
#define GETSOCKETERRNO() (errno) //Содержит последнюю ошибку 
#endif


#include <stdio.h> //потоковый ввод и вывод
#include <string.h> // функции для работы сос троками, memset
#include <time.h> //для работы со временем

//точка входа 
int main() {

//Для виндоус
#if defined(_WIN32)
    WSADATA d;
    //WSAStartup инициализирует библиотеку Winsock. MAKEWORD(2,2) просит версию 2.2.
    if (WSAStartup(MAKEWORD(2, 2), &d)) {
        fprintf(stderr, "Failed to initialize.\n");
        return 1;
    }
#endif

    //Общий код, для Windows и UNIX
    //Настройка локального адреса
    printf("Configuring local address...\n");
    struct addrinfo hints; //Структура подсказка, что бы сообщить системе, какой адрес нам нужен
    memset(&hints, 0, sizeof(hints)); //Заполняем структуру нулями
    hints.ai_family = AF_INET; //IPv4
    hints.ai_socktype = SOCK_STREAM; // Правила для TCP
    hints.ai_flags = AI_PASSIVE; //автоматически подставляет адрес локального хоста 

    struct addrinfo *bind_address;
    // getaddrinfo преобразует имя хоста и имя сервиса в структуру с адресом.
    // Первый аргумент 0 (NULL) означает "любой локальный адрес".
    // Второй аргумент "8080" - это порт.
    getaddrinfo(0, "8080", &hints, &bind_address);

    //Создание сокета
    printf("Creating socket...\n");
    SOCKET socket_listen;
    //Заполняем сокет из bind_address
    socket_listen = socket(bind_address->ai_family, bind_address->ai_socktype, bind_address->ai_protocol);
    //Проверка на ошибки 
    if (!ISVALIDSOCKET(socket_listen)) {
        fprintf(stderr, "socket() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }

    //Объединяем сокет и адрес
    printf("Binding socket to local address...\n");
    if (bind(socket_listen, bind_address->ai_addr, bind_address->ai_addrlen)) {
        fprintf(stderr, "bind() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }
    //освобождаем память от адресной структуры bind_adress
    freeaddrinfo(bind_address);

    //прослушиваем сокет 
    printf("Listening...\n");
    if (listen(socket_listen, 10) < 0) {
        fprintf(stderr, "listen() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }

    //Ожидание присоединения 
    printf("Waiting for connection...\n");
    // Достаточно большая структура для любого адреса (IPv4/v6)
    struct sockaddr_storage client_address;
    socklen_t client_len = sizeof(client_address);
    SOCKET socket_client = accept(socket_listen,
            (struct sockaddr*) &client_address, &client_len);
    if (!ISVALIDSOCKET(socket_client)) {
        fprintf(stderr, "accept() failed. (%d)\n", GETSOCKETERRNO());
        return 1;
    }

    //определяем адрес клиента 
    printf("Client is connected... ");
    char address_buffer[100];
    getnameinfo((struct sockaddr*)&client_address,
            client_len, address_buffer, sizeof(address_buffer), 0, 0,
            NI_NUMERICHOST);
    printf("%s\n", address_buffer);


    printf("Reading request...\n");
    char request[1024];
    int bytes_received = recv(socket_client, request, 1024, 0);
    printf("Received %d bytes.\n", bytes_received);
    //printf("%.*s", bytes_received, request);

    
    printf("Sending response...\n");
    const char *response =
        "HTTP/1.1 200 OK\r\n"
        "Connection: close\r\n"
        "Content-Type: text/plain\r\n\r\n"
        "Local time is: ";
    int bytes_sent = send(socket_client, response, strlen(response), 0);
    printf("Sent %d of %d bytes.\n", bytes_sent, (int)strlen(response));

    time_t timer;
    time(&timer);
    char *time_msg = ctime(&timer);
    bytes_sent = send(socket_client, time_msg, strlen(time_msg), 0);
    printf("Sent %d of %d bytes.\n", bytes_sent, (int)strlen(time_msg));


    printf("Closing connection...\n");
    CLOSESOCKET(socket_client);

    printf("Closing listening socket...\n");
    CLOSESOCKET(socket_listen);


#if defined(_WIN32)
    WSACleanup();
#endif


    printf("Finished.\n");

    return 0;
}