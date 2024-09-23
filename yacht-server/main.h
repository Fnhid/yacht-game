#pragma once
#ifndef MAIN_H
#define MAIN_H

#pragma comment(lib, "ws2_32")

#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h> 
#include <string>
#include <thread>
#include <vector>

using namespace std;

#define MAX_CLIENT 2
#define PORT 6666
#define BUFSIZE 32

int main();
void acceptClients(int i);
void prepareClients(int i);
void gameClients(int i);
void initServer();
void errorHandling(const char* e);

#endif
