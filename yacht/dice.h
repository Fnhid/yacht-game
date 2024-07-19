#pragma once
#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "interface.h"
#include <limits>

using namespace std;

enum Ranking {
    ACES,
    TWOS,
    THREES,
    FOURS,
    FIVES,
    SIXES,
    CHANCE,
    THREE_OF_A_KIND,
    FOUR_OF_A_KIND,
    FULL_HOUSE,
    SMALL_STRAIGHT,
    LARGE_STRAIGHT,
    YAHTZEE
};

class Dice {
private:
    int _value[5] = { 0,0,0,0,0 };
    bool _isChangeable[5] = { 1,1,1,1,1 };
public:
    bool isDiceChangeable(int idx);
    int GetDiceValue(int idx);
    void RollDice();
    void SetDiceChangeable(int idx);
    Ranking CheckRank();
};

#endif