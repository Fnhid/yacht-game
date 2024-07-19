#include "dice.h"

void Dice::RollDice() {
	random_device rd;
	mt19937 mt(rd()); // for stable random
	srand(static_cast<unsigned int> (time(NULL))); // for animation random
	int tmp;

	for (int i = 0; i < 5; i++) {
		if (!_isChangeable[i]) continue;
		uniform_int_distribution<int> dist(1, 6);
		_value[i] = dist(mt);
	}

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 5; j++) {
			if (!_isChangeable[j]) continue;
			tmp = rand() % 6 + 1;
			Sleep(100);
			gotoxy(50 + 5 * i, 9);
			cout << tmp;
		}
	}
	for (int i = 0; i < 5; i++) {
		if (!_isChangeable[i]) continue;
		tmp = rand() % 6 + 1;
		Sleep(500);
		gotoxy(50 + 5 * i, 9);
		cout << tmp;
	}
}


bool Dice::isDiceChangeable(int idx) {
	return _isChangeable[idx];
}
int Dice::GetDiceValue(int idx) {
	return _value[idx];
}

