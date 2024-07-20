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
#include <vector>
#include <conio.h>

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
    vector<int> _frozenValue;
    int _frozenIdx[5] = {-1,-1,-1,-1,-1};
    bool _isChangeable[5] = { 1,1,1,1,1 };
    bool _isfrozen[5] = { 0,0,0,0,0 };
public:
    bool isDiceChangeable(int idx);
    bool isDicefrozen(int idx);
    void SetDicefrozen(int idx);
    int GetDiceValue(int idx);
    void RollDice();
    bool SetDiceChangeable(int idx, bool setState);
    int getDiceRank(int idx);
    void PrintfrozenDice();
};

#endif