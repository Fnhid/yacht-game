#pragma once
#ifndef INTERFACE_H
#define INTERFACE_H

#include "global.h"

#define KEY_UP    72
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_DOWN  80
#define ENTER 13

enum Color {
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
void gotoxy(int x, int y);
void SetColor(Color text, Color back);
void clearY(int x);
#endif // !INTERFACE_H
