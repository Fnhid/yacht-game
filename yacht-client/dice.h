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
    void setDiceFrozen(int idx);
    int getDiceValue(int idx);
    int getFrozenValue(int idx);
    int getFrozenIdx(int idx);
    void rollDice(); // for local game
    void rollDice(SOCKET& serverSock); // for turn user
    void rollDice(char val[BUFSIZE]); // for non-turn user
    bool setDiceChangeable(int idx);
    bool setDiceUnchangeable(int idx);
    int getDiceRank(int idx);
    void printFrozenDice();
};


#endif