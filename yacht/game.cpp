
#include "game.h"
Player::Player(int idx, int score[15], string name) {
	SetPlayer(idx, score, name);
}

void Player::SetPlayer(int idx, int score[15], string name) {
	_idx = idx;
	if (name == "Player") name += (" " + to_string(idx));
	_name = name;
	for (int i = 0; i < 15; i++) _score[i] = score[i];

}

int Player::SetRank(int idx, int score) {
	if (idx < 1 || idx > 15) return -1;
	idx -= 1;
	_score[idx] = score;
	return 0;
}

int game(int game_type) {
	string player_name;
	system("mode con:cols=130 lines=40");
	gotoxy(55, 5);
	Player* players[2];

	if (game_type == 1) {
		
		for (int i = 0; i < 2; i++) {
			system("mode con:cols=130 lines=40");
			gotoxy(45, 5);
			cout << "Name of Player " << (i + 1) << ": ";
			cin >> player_name;
			players[i] = new Player(i, 0, player_name); 


			
		}
	} 
	else if (game_type == 2) {
		// game with computer
		system("mode con:cols=130 lines=40");
		gotoxy(45, 5);
		cout << "Name of Player: ";
		cin >> player_name;
		players[0] = new Player(0, 0, player_name);
		players[1] = new Player(1, 0, "computer");
		
	}
	else {
		// exception
		return 0;
	}


	for (int i = 0; i < 2; i++) {
		delete players[i];
	}
	
	
	return 0;
}
