#pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

enum Color{
    BLACK,
    DARK_BLUE,
    DARK_GREEN,
    DARK_SKYBLUE,
    DARK_RED,
    DARK_VOILET,
    DAKR_YELLOW,
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

enum Ranking{
    ACES,
    TWOS,
    THREES,
    FOURS,
    FIVES,
    SIXES,
    THREE_OF_A_KIND,
    FOUR_OF_A_KIND,
    FULL_HOUSE,
    SMALL_STRAIGHT,
    LARGE_STRAIGHT,
    CHANCE,
    YAHTZEE,
    BONUS,
    YAHTZEE_BONUS
};

void setColor(unsigned short text, unsigned short back);


struct dice {
    int value[5] = { 0,0,0,0,0 };
    bool isChangeable[5] = { 1,1,1,1,1 };
};

class Player {
private:
    int _idx;
    string _name;
    int _score[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    bool _scored[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; // check if scored

public:
    Player() {
        _idx = 0;
        _name = "player";
    }
    Player(int idx, string name);
    int SetRank(int idx, int score);
    int GetRank(int idx);
    string GetName();
};

void SetGameInterface(Player players[2], dice& dice);
int game(int game_type);
Ranking checkRank();
void gotoxy(int x, int y);
void rollDice(dice& dice);

#endif // !GAME_H
