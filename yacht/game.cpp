
#include "game.h"

Player::Player(int idx, string name) {
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

void gotoxy(int x, int y) {
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void SetColor(Color text, Color back) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

void SetGameInterface(Player players[2], dice& dice) {
	int a;
	// dice UI
	for (int i = 0; i < 5; i++) { // dice_x 50~70
		gotoxy(50 + 5 * i, 11);
		cout << dice.value[i];
	}


	SetColor(WHITE, DARK_RED);
	gotoxy(40, 13);
	cout << players[0].GetName();
	gotoxy(75, 13);
	cout << players[1].GetName();

	// scoreboard UI
	gotoxy(50, 13);
	cout << "[     * RANK *     ]";
	gotoxy(50, 14);
	cout << "|       ACES       |";
	gotoxy(50, 15);
	cout << "|       TWOS       |";
	gotoxy(50, 16);
	cout << "|      THREES      |";
	gotoxy(50, 17);
	cout << "|       FOURS      |";
	gotoxy(50, 18);
	cout << "|       FIVES      |";
	gotoxy(50, 19);
	cout << "|       SIXES      |";
	gotoxy(50, 20);
	cout << "|**  ** BONUS ** **|";
	gotoxy(50, 21);
	cout << "|  THREE OF A KIND |";
	gotoxy(50, 22);
	cout << "|  FOUR OF A KIND  |";
	gotoxy(50, 23);
	cout << "|    FULL HOUSE    |";
	gotoxy(50, 24);
	cout << "|  SMALL STRAIGHT  |";
	gotoxy(50, 25);
	cout << "|  LARGE STRAIGHT  |";
	gotoxy(50, 26);
	cout << "|      CHANCE      |";
	gotoxy(50, 27);
	cout << "|     YAHTZEE!     |";
	gotoxy(50, 28);
	cout << "| * YAHTZEE BONUS *|";
	

	SetColor(WHITE, BLACK);
	for (int i = 0; i < 13; i++) {
		gotoxy(40, 14+i);
		cout << players[0].GetRank(i);
		gotoxy(75, 14 + i);
		cout << players[1].GetRank(i);

	}	
	

	cin >> a;

}


int game(int game_type) {
	
	system("mode con:cols=130 lines=40");
	gotoxy(55, 5);
	Player players[2];
	dice dice;
	
	if (game_type == 1) {
		
		for (int i = 0; i < 2; i++) {
			string player_name;
			system("mode con:cols=130 lines=40");
			gotoxy(45, 5);
			cout << "Name of Player " << (i + 1) << ": ";
			cin >> player_name;
			players[i] = Player(i, player_name); 


			
		}
	} 
	else if (game_type == 2) {
		// game with computer
		string player_name;
		system("mode con:cols=130 lines=40");
		gotoxy(45, 5);
		cout << "Name of Player: ";
		cin >> player_name;
		player_name.resize(20);
		players[0] = Player(0, player_name);
		players[1] = Player(1, "computer");
		
	}
	else {
		// exception
		return 0;
	}
	for (int round = 1; round < 13; round++) {
		system("mode con:cols=130 lines=40");
		gotoxy(55, 5);
		cout << "[ * Round " << round << " * ]";
		
		SetGameInterface(players, dice);

		

	}



	
	
	
	return 0;
}
