#include "game.h"

void SetColor(Color text, Color back) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

void SetGameInterface(Player players[2], Dice dice, int round) {
	int a;

	system("mode con:cols=130 lines=40");
	gotoxy(52, 5);
	cout << "[ * Round " << ((round+1) / 2) << " * ]";

	// dice UI
	for (int i = 0; i < 5; i++) { // dice_x 50~70
		gotoxy(50 + 5 * i, 9);
		cout << dice.GetDiceValue(i);
	}


	if (round % 2 == 1) {
		SetColor(WHITE, GREEN);
		gotoxy(40, 13);
		cout << players[0].GetName();
		SetColor(WHITE, DARK_GRAY);
		gotoxy(75, 13);
		cout << players[1].GetName();
	}
	else {
		SetColor(WHITE, DARK_GRAY);
		gotoxy(40, 13);
		cout << players[0].GetName();
		SetColor(WHITE, GREEN);
		gotoxy(75, 13);
		cout << players[1].GetName();
	}
	
	SetColor(WHITE, RED);

	// scoreboard UI
	gotoxy(50, 13);
	cout << "[====== RANK =======]";
	gotoxy(50, 14);
	cout << "|       ACES        |";
	gotoxy(50, 15);
	cout << "|       TWOS        |";
	gotoxy(50, 16);
	cout << "|      THREES       |";
	gotoxy(50, 17);
	cout << "|       FOURS       |";
	gotoxy(50, 18);
	cout << "|       FIVES       |";
	gotoxy(50, 19);
	cout << "|       SIXES       |";
	gotoxy(50, 20);
	cout << "| *    SUBTOTAL   * |";
	gotoxy(50, 21);
	cout << "|**  ** BONUS **  **|";
	gotoxy(50, 22);
	cout << "|       CHANCE      |";
	gotoxy(50, 23);
	cout << "|  THREE OF A KIND  |";
	gotoxy(50, 24);
	cout << "|   FOUR OF A KIND  |";
	gotoxy(50, 25);
	cout << "|     FULL HOUSE    |";
	gotoxy(50, 26);
	cout << "|   SMALL STRAIGHT  |";
	gotoxy(50, 27);
	cout << "|   LARGE STRAIGHT  |";
	gotoxy(50, 28);
	cout << "|      YAHTZEE!     |";
	gotoxy(50, 29);
	cout << "|------ TOTAL ------|";
	

	SetColor(WHITE, BLACK);
	for (int i = 0; i < 6; i++) {
		gotoxy(40, 14+i);
		if (players[0].GetRank(i) == -1) cout << "--";
		else cout << players[0].GetRank(i);
		gotoxy(75, 14 + i);
		if (players[1].GetRank(i) == -1) cout << "--";
		else cout << players[1].GetRank(i);

	}	// 1~6

	gotoxy(40, 20); // subtotal

	if (players[0].GetRank(13) >= 63) SetColor(SKYBLUE, DARK_GRAY);
	else SetColor(RED, BLACK);
	cout << players[0].GetRank(13) << " / 63";
	gotoxy(75, 20);
	if (players[1].GetRank(13) >= 63) SetColor(SKYBLUE, DARK_GRAY);
	else SetColor(RED, BLACK);
	cout << players[1].GetRank(13) << " / 63";

	gotoxy(40, 21); // bonus
	if (players[0].GetRank(13) >= 63) {
		SetColor(SKYBLUE, BLACK);
		cout << "+ 35";
	}
	else {
		SetColor(DARK_GRAY, BLACK);
		cout << "+ 35";
	}
	gotoxy(75, 21);
	if (players[1].GetRank(13) >= 63) {
		SetColor(SKYBLUE, GRAY);
		cout << "+ 35";
	}
	else {
		SetColor(DARK_GRAY, BLACK);
		cout << "+ 35";
	}
	SetColor(WHITE, BLACK);
	
	for (int i = 6; i < 13; i++) {
		gotoxy(40, 16 + i);
		if (players[0].GetRank(i) == -1) cout << "--";
		else cout << players[0].GetRank(i);
		gotoxy(75, 16 + i);
		if (players[1].GetRank(i) == -1) cout << "--";
		else cout << players[1].GetRank(i);
	} // other ranks

	gotoxy(40, 29);
	cout << players[0].GetRank(15);
	gotoxy(75, 29);
	cout << players[1].GetRank(15);
	

	cin >> a;

}


int game(int game_type) {
	
	system("mode con:cols=130 lines=40");
	gotoxy(55, 5);
	Player players[2];
	
	if (game_type == 1) {
		
		for (int i = 0; i < 2; i++) {
			string player_name;
			system("mode con:cols=130 lines=40");
			gotoxy(45, 5);
			cout << "Name of Player " << (i + 1) << ": ";
			cin >> player_name;
			players[i].SetPlayer(i, player_name); 
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
		players[0].SetPlayer(0, player_name);
		players[1].SetPlayer(1, "computer");
		
	}
	else {
		// exception
		return 0;
	}

	for (int round = 1; round <= 26; round++) { // odd round : 1p, even round : 2p
		Dice* dice = new Dice();
		SetGameInterface(players, *dice, round);

		
		delete dice;
	}



	
	
	system("mode con:cols=130 lines=40 && color 0F");
	return 0;
}
