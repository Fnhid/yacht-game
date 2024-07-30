#pragma once
#ifndef DICE_H
#define DICE_H

#include "global.h"
#include "interface.h"
#include <conio.h>
#include <random>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>

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
    int _frozenIdx[5] = { -1,-1,-1,-1,-1 };
    bool _isChangeable[5] = { 1,1,1,1,1 };
    bool _isFrozen[5] = { 0,0,0,0,0 };
public:
    bool isDiceChangeable(int idx);
    bool isDiceFrozen(int idx);
    void SetDiceFrozen(int idx);
    int GetDiceValue(int idx);
    int GetFrozenValue(int idx);
    int GetFrozenIdx(int idx);
    void RollDice(); // for local game
    void RollDice(SOCKET& serverSock); // for turn user
    void RollDice(char val[BUFSIZE]); // for non-turn user
    bool SetDiceChangeable(int idx, bool setState);
    int GetDiceRank(int idx);
    void PrintfrozenDice();
};


#endif