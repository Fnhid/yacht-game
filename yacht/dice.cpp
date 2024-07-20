#include "dice.h"

void Dice::RollDice() {
	random_device rd;
	mt19937 mt(rd()); // for stable random
	srand(static_cast<unsigned int> (time(NULL))); // for animation random
	int tmp, c=0;


	for (int i = 0; i < 5;i++) {
		if (!_isChangeable[i]) {
			gotoxy(50 + 5 * i, 11);
			cout << ' ';
			continue;
		}
		else {
			uniform_int_distribution<int> dist(1, 6);

			_value[i] = dist(mt);
		}
	}
	while(true) {
		if (_kbhit()) {
			c = _getch();
			if (c == ENTER) break;
		}
	}

	SetColor(WHITE, BLACK);
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 20; i++) {
			for (int j = k; j < 5; j++) {
				if (!_isChangeable[j]) continue;
				tmp = rand() % 6 + 1;
				Sleep(5);
				gotoxy(50 + 5 * j, 11);
				cout << tmp;
			}
		}
		if (_isChangeable[k]) {
			gotoxy(50 + k * 5, 11);
			cout << _value[k];
		}
	}
}
bool Dice::isDicefrozen(int idx) {
	return _isfrozen[idx];
}
void Dice::SetDicefrozen(int idx) {
	_isfrozen[idx] = true;
}

bool Dice::isDiceChangeable(int idx) {
	return _isChangeable[idx];
}

void Dice::PrintfrozenDice() {
	SetColor(WHITE, BLACK);
	auto iter = _frozenValue.begin();

	for (int i = 0; i < 5; i++) {
		if (iter != _frozenValue.end()) {
			gotoxy(50 + 5 * i, 8);

			
			cout << *iter;
			iter++;
		}

		else {
			gotoxy(50 + 5 * i, 8);
			cout << " ";
		}
	}
}

bool Dice::SetDiceChangeable(int idx, bool setState) {
	if (setState) {
		if (_isChangeable[idx] == false) {
			_isChangeable[idx] = true;
			gotoxy(50 + 5 * idx, 11);
			SetColor(WHITE, BLACK);
			cout << _value[idx];
			_frozenValue.erase(_frozenValue.begin() + _frozenIdx[idx]);
			_frozenIdx[idx] = -1;
			int frozenIdxCopy[5];
			int rank = 0;
			copy(begin(_frozenIdx), end(_frozenIdx), begin(frozenIdxCopy));
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (frozenIdxCopy[j] == i) {
						_frozenIdx[j] = rank;
						rank++;
						break;
					}
				}
			}
			PrintfrozenDice();
		}
		else return false;
	}
	else {
		if (_isChangeable[idx] == true) {
			_isChangeable[idx] = false;
			gotoxy(50 + 5 * idx, 11);
			SetColor(DARK_GRAY, BLACK);
			cout << _value[idx];
			_frozenIdx[idx] = _frozenValue.size();
			_frozenValue.push_back(_value[idx]);
			PrintfrozenDice();
		}
		else return false;
	}
	SetColor(WHITE, BLACK);
	return true;
}
int Dice::GetDiceValue(int idx) {
	return _value[idx];
}

int Dice::getDiceRank(int idx) {
	int score = 0, val_arr[6] = {};
	bool f, f2, f3;
	for (int i : _frozenValue) val_arr[i-1]++;

	switch (idx) {
	case 0: // aces
		for (auto  i: _frozenValue) if (i == 1) score++;
		break;

	case 1:
		for (auto  i: _frozenValue) if (i == 2) score += 2;
		break;
	case 2:
		for (auto  i: _frozenValue) if (i == 3) score += 3;
		break;
	case 3:
		for (auto  i: _frozenValue) if (i == 4) score += 4;
		break;
	case 4:
		for (auto  i: _frozenValue) if (i == 5) score += 5;
		break;
	case 5: // sixes
		for (auto  i: _frozenValue) if (i == 6) score += 6;
		break;
	case 6: // chance
		for (auto  i: _frozenValue) score += i;
		break;
	case 7: // three of a kind
		for (int i = 0; i < 6;i++ ) if (val_arr[i] >= 3) score += 3 * (i+1);	
		break;
	case 8: // four of a kind
		for (int i = 0; i < 6; i++) if (val_arr[i] >= 4) score += 4 * (i + 1);
		break;

	case 9: // full house
		f2 = false, f3 = false;
		for (auto  i: val_arr) {
			if (i == 3) f3 = true;
			if (i == 2) f2 = true;
		}
		if (f2 && f3) for (auto j : _frozenValue) score += j;
		break;
	case 10: // little straight 
		for (int i = 0; i < 3; i++) {
			f = true;
			for (int j = 0; j < 2; j++) {
				if (_frozenValue[i + j] + 1 != _frozenValue[i + j +1]) f = false;
			}
			if (f) {
				break;
			}
		}

		if (f) {
		    score += 30;
		}
		break;

	case 11: // big straight
		

		for (int i = 0; i < 2; i++) {
			f = true;
			for (int j = 0; j < 3; j++) {
				if (_frozenValue[i + j] + 1 != _frozenValue[i + j+1] ) f = false;
			}
			if (f) {
				break;
			}
		}

		if (f) {
			score += 30;
		}
		break;
	case 12: // yahtzee
		for (auto i : val_arr) if (i >= 5) score += 50;
		break;
	default:
		break;
	}
		return score;

}
