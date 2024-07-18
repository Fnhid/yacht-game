
#pragma once

#include <iostream>
#include <string>
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

void setColor(unsigned short text);
int game();
int setInterface();
Ranking checkRank();


class Player {
private:
    int _idx;
    string _name;
    int _score[15];
public:
    Player(int idx, int score[15], string name ="Player");
    void SetPlayer(int idx, int score[15], string name );
    int SetRank(int idx, int score);

};

Player::Player(int idx, int score[15], string name ="Player") {
    SetPlayer(idx, score, name);
}

void Player::SetPlayer(int idx, int score[15], string name ) {
    _idx = idx;
    if (name == "Player") name += (" " + to_string(idx));
    _name = name;
    for (int i = 0; i < 15; i++) _score[i] = score[i];
    
}

int Player::SetRank(int idx, int score) {
    if (idx < 1 || idx > 15) return -1;
    idx -= 1;
    _score[idx] = score;
}

