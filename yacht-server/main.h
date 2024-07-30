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
void AcceptClients(int i);
void PrepareClients(int i);
void GameClients(int i);
void InitServer();
void ErrorHandling(const char* e);

typedef struct {
	int type;
	int info[5];
} sockData;

#endif
