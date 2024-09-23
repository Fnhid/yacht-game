#pragma once
#ifndef GAME_H
#define GAME_H


// Socket
#ifndef _WINSOCK2API_
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <windows.h>
#endif 

#include "global.h"
#include "interface.h"
#include "player.h"
#include "dice.h"

#define PORT 6666

#pragma comment(lib, "ws2_32")

void scoreHelp();
void setGameInterface(Player players[2], Dice dice, int round);
int game(int game_type);
void gotoxy(int x, int y);

#endif 
