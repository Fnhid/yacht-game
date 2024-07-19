#include "dice.h"

void Dice::RollDice() {
	random_device rd;
	mt19937 mt(rd()); // for stable random
	srand(static_cast<unsigned int> (time(NULL))); // for animation random
	int tmp;


	for (int i = 0; i < 5; i++) {
		if (!isDiceChangeable(i)) {
			SetColor(DARK_GREEN, BLACK);
			gotoxy(50 + 5 * i, 11);
			cout << GetDiceValue(i);
			continue;
		}
		uniform_int_distribution<int> dist(1, 6);
		_value[i] = dist(mt);
	}
	cin.ignore(32467, '\n');
	cin.ignore(32467, '\n');

	SetColor(WHITE, BLACK);
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 20; i++) {
			for (int j = k; j < 5; j++) {
				if (!isDiceChangeable(j)) continue;
				tmp = rand() % 6 + 1;
				Sleep(5);
				gotoxy(50 + 5 * j, 11);
				cout << tmp;
			}
		}
		if (_isChangeable[k]) {
			gotoxy(50 + k * 5, 11);
			cout << GetDiceValue(k);
		}
	}
}


bool Dice::isDiceChangeable(int idx) {
	return _isChangeable[idx];
}
void Dice::SetDiceChangeable(int idx) {
	if (_isChangeable[idx] == TRUE) _isChangeable[idx] = FALSE;
	else _isChangeable[idx] = TRUE;
	gotoxy(50 + 5 * idx, 11);
	if (_isChangeable[idx]) SetColor(WHITE, BLACK);
	else SetColor(GREEN, BLACK);
	cout << GetDiceValue(idx);
	SetColor(WHITE, BLACK);
}
int Dice::GetDiceValue(int idx) {
	return _value[idx];
}

