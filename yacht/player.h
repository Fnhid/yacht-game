#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "interface.h"

using namespace std;

class Player {
private:
    int _idx=0;
    string _name="player";
    int _score[16] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0 };
    // 0~12 follows ranking,
    // 13 is subtotal,
    // 14 is bonus,
    // 15 is total.

public:
    void SetPlayer(int idx, string name);
    int SetRank(int idx, int score);
    int GetRank(int idx);
    string GetName();
};

#endif