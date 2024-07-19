#include "player.h"

void Player::SetPlayer(int idx, string name) {
	_idx = idx;
	_name = name;
	if (_name == "Player") name += (" " + to_string(idx));

}

int Player::SetRank(int idx, int score) {
	if (idx < 1 || idx > 15) return -1;
	idx -= 1;
	_score[idx] = score;
	return 0;
}
string Player::GetName() {
	return _name;

}
int Player::GetRank(int idx) {
	if (idx < 0 || idx > 15) return -1;
	int score = _score[idx];
	return score;
}