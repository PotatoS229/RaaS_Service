#if defined(_WIN32)
#ifdef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib")
#endif
#else
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#endif

#include <stdio.h>
#include <string.h>

//определяем макросы 
#if defined(_WIN32)
//Для прповерки валидности сокета 
#define ISVALIDSOCKET(s) ((s) != INVALID_SOCKET)
//Закрытие сокета
#define CLOSESOCKET(s) closesocket(s)
//последняя ошибка
#define GETSOCKETERRNO() (WSAGetLastError())
#else 
//Проверка на валидность для соокета
#define ISVALIDSOCKET(s) ((s) >=0)
//Закртыие сокета
#define CLOSESOCKET(s) close(s)
//последняя ошибка
#define GETSOCKETERRNO() (errno)
#endif