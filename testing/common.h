#if defined(_WIN32)
#ifdef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma commen(lib,"ws2_32.lib")
#else
#include <sys/socket.h> //хрорфин все фукнкции для сокетов
#include <sys/types.h> //для переносимости кода и определения системных типов
#include <netinet/in.h> //содержит структуры и не только для работы с сокетами
#include <arpa/inet.h> // для преобразования адресов в комп вид
#include <netdb.h> // используется как справочное бюро, через него можно получить любую инфу 
#include <errno.h> // хранит последнюю ошибку
#include <unistd.h> //системные команды 
#endif

//Общие 
#include <stdio.h>
#include <string.h>

//Определеие макросов 
#if defined(_WIN32)
//проверка валидности кода 
#define ISVALIDSOCKET(s) ((s) != INVALID_SOCKET)
// проверка на ошибку
#define GETERRNO (WSAGetLastError())
//
#define CLOSESOCKET(s) closesocket(s)
#else
//проверка валидности кода 
#define ISVALID_SOCKET(s) ((s) >=0)
// проверка на ошибку
#define GETERRNO() (errno)
// Закрытие сокетов
#define CLOSESOCKET(s) close(s)
#define SOCKET int
#endif