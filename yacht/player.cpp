#include "player.h"

void Player::SetPlayer(int idx, string name) {
	_idx = idx;
	_name = name;
	if (_name == "Player") name += (" " + to_string(idx));

}

void Player::SetRank(int idx, int score) {
	_score[idx] = score;
	if (idx <= 5) _score[13] += score;
	_score[15] += score;

	if (!_gotBonus&& _score[13] >= 63) {
		_gotBonus = true;
		_score[14] = 35; 
		_score[15] += 35;

	}


}
string Player::GetName() {
	return _name;

}
int Player::GetRank(int idx) {
	if (idx < 0 || idx > 15) return -1;
	int score = _score[idx];
	return score;
}