
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
	
	if (game_type == 1) {
		int players_num;
		string player_name;
		system("mode con:cols=130 lines=40");
		gotoxy(55, 5);
		cout << "Please enter the number of players\n>> ";
		cin >> players_num;
		Player* players = new Player[players_num];
		for (int i = 0; i < players_num; i++) {
			system("mode con:cols=130 lines=40");
			gotoxy(55, 5);
			cout << "Name of Player " << (i + 1) << ": ";
			cin >> player_name;
			players[i] = Player::SetPlayer(i, 0, player_name); 
		}
		
	} 
	else if (game_type == 2) {
		// game with computer
		cout << "computer";
	}
	
	return 0;
}
