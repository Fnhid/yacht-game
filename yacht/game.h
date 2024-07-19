#pragma once
#ifndef GAME_H
#define GAME_H


#include <iostream>
#include <string>
#include <windows.h>

#include "interface.h"
#include "player.h"
#include "dice.h"

using namespace std;

enum Color{
    BLACK,
    DARK_BLUE,
    DARK_GREEN,
    DARK_SKYBLUE,
    DARK_RED,
    DARK_VOILET,
    DARK_YELLOW,
    GRAY,
    DARK_GRAY,
    BLUE,
    GREEN,
    SKYBLUE,
    RED,
    VIOLET,
    YELLOW,
    WHITE,
};



void SetColor(Color text, Color back);

void SetGameInterface(Player players[2], Dice dice, int round);
int game(int game_type);
void gotoxy(int x, int y);

#endif 
