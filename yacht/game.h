#pragma once
#ifndef GAME_H
#define GAME_H



#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "interface.h"
#include "player.h"
#include "dice.h"

using namespace std;






void SetGameInterface(Player players[2], Dice dice, int round);
int game(int game_type);
void gotoxy(int x, int y);

#endif 
