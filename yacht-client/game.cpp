#include "game.h"

void ScoreHelp() {
	clearY(34);
	SetColor(WHITE, DARK_GRAY);
	gotoxy(98, 35);
	cout << "╔══════════════════════════╗";
	gotoxy(98, 36);
	cout << "║        Move : ↑ ↓        ║";
	gotoxy(98, 37);
	cout << "║                          ║";
	gotoxy(98, 38);
	cout << "║       Select: Enter      ║";
	gotoxy(98, 39);
	cout << "╚══════════════════════════╝";
	SetColor(WHITE, BLACK);
}

void SetGameInterface(Player players[2], Dice dice, int round) {

	system("mode con:cols=130 lines=40");
	gotoxy(52, 2);
	cout << "[ * Round " << ((round + 1) / 2) << " * ]";

	// dice UI
	gotoxy(48, 6);
	cout << "Press ENTER to roll dice";
	for (int i = 0; i < 5; i++) { // dice_x 50~70
		gotoxy(50 + 5 * i, 11);
		cout << '?';
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
	cout << "╔══════ RANK ═══════╗";
	gotoxy(50, 14);
	cout << "║     * ACES  *     ║";
	gotoxy(50, 15);
	cout << "║    ** TWOS  **    ║";
	gotoxy(50, 16);
	cout << "║   *** THREES***   ║";
	gotoxy(50, 17);
	cout << "║  **** FOURS ****  ║";
	gotoxy(50, 18);
	cout << "║ ***** FIVES ***** ║";
	gotoxy(50, 19);
	cout << "║****** SIXES ******║";
	gotoxy(50, 20);
	cout << "║   // SUBTOTAL //  ║";
	gotoxy(50, 21);
	cout << "║    ++ BONUS ++    ║";
	gotoxy(50, 22);
	cout << "║?      CHANCE     ?║";
	gotoxy(50, 23);
	cout << "║3 THREE OF A KIND 3║";
	gotoxy(50, 24);
	cout << "║4  FOUR OF A KIND 4║";
	gotoxy(50, 25);
	cout << "║F    FULL HOUSE   F║";
	gotoxy(50, 26);
	cout << "║s LITTLE STRAIGHT s║";
	gotoxy(50, 27);
	cout << "║S   BIG STRAIGHT  S║";
	gotoxy(50, 28);
	cout << "║$     YAHTZEE!    $║";
	gotoxy(50, 29);
	cout << "╚══════ TOTAL ══════╝";

	SetColor(WHITE, DARK_GRAY);
	gotoxy(98, 34);
	cout << "╔══════════════════════════╗";
	gotoxy(98, 35);
	cout << "║   Move : ← →             ║";
	gotoxy(98, 36);
	cout << "║   Freeze : ↑             ║";
	gotoxy(98, 37);
	cout << "║   Unfreeze : ↓           ║";
	gotoxy(98, 38);
	cout << "║   Roll & Select: Enter   ║";
	gotoxy(98, 39);
	cout << "╚══════════════════════════╝";

	SetColor(WHITE, BLACK);
	for (int i = 0; i < 6; i++) {
		gotoxy(40, 14 + i);
		if (players[0].GetRank(i) == -1) cout << "--";
		else cout << players[0].GetRank(i);
		gotoxy(75, 14 + i);
		if (players[1].GetRank(i) == -1) cout << "--";
		else cout << players[1].GetRank(i);

	}	// 1~6

	gotoxy(40, 20); // subtotal

	if (players[0].GetRank(13) >= 63) SetColor(GREEN, BLACK);
	else SetColor(RED, BLACK);
	cout << players[0].GetRank(13) << " / 63";
	gotoxy(75, 20);
	if (players[1].GetRank(13) >= 63) SetColor(GREEN, BLACK);
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
		SetColor(SKYBLUE, BLACK);
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

	for (int round = 1; round <= 26; round++) { // odd round : 1p, even round : 2p
		Dice* dice = new Dice();

		SetGameInterface(players, *dice, round);
		cin.clear();
		for (int attempt = 3; attempt > 0; attempt--) {
			int idx = 0;
			int c = 0;
			bool nf = false; // raise when enter key is pressed 
			dice->PrintfrozenDice();
			dice->RollDice();
			cin.clear();
			gotoxy(51, 4);
			cout << attempt - 1 << " reload(s) left";
			gotoxy(36, 5);
			cout << "Select dices to freeze and press ENTER to reroll";
			while (!nf) {
				if (_kbhit()) {
					c = _getch();
					if (c == 224 || c == 0) {
						switch ((c = _getch())) {
						case KEY_LEFT:
							gotoxy(50 + 5 * idx, 10);
							cout << " ";
							do {
								if (idx == 0) idx = 4;
								else idx--;

							} while (dice->isDiceFrozen(idx));
							gotoxy(50 + 5 * idx, 10);
							cout << "↓";

							break;
						case KEY_RIGHT:
							gotoxy(50 + 5 * idx, 10);
							cout << " ";
							do {
								if (idx == 4) idx = 0;
								else idx++;

							} while (dice->isDiceFrozen(idx));
							gotoxy(50 + 5 * idx, 10);
							cout << "↓";
							break;
						case KEY_UP:
							dice->SetDiceChangeable(idx, false);
							cin.clear();
							break;
						case KEY_DOWN:
							dice->SetDiceChangeable(idx, true);
							cin.clear();
							break;
						default:
							break;
						}
					}

					if (c == ENTER) {
						nf = true;
						gotoxy(50 + 5 * idx, 10);
						cout << " ";
						for (int i = 0; i < 5; i++) if (!dice->isDiceChangeable(i)) dice->SetDiceFrozen(i);
					}

				}
			}
		}

		for (int i = 0; i < 5; i++) {
			if (dice->isDiceChangeable(i)) {
				dice->SetDiceChangeable(i, false);
			}
		}

		clearY(5);
		clearY(4);

		gotoxy(45, 6);
		cout << "    Select the rank to score   ";


		ScoreHelp();

		int idx = 0, c = 0, arrow_x;
		bool nf = false; // raise when enter key is pressed 
		while (players[(round + 1) % 2].GetRank(idx) != -1) idx++;

		if (round % 2 == 1) arrow_x = 38;
		else arrow_x = 78;
		cin.clear();
		while (!nf) {
			if (_kbhit()) {
				c = _getch();
				if (c == 224 || c == 0) {
					switch ((c = _getch())) {
					case KEY_UP:
						if (idx <= 5) gotoxy(arrow_x, 14 + idx);
						else gotoxy(arrow_x, 16 + idx);
						cout << " ";
						do {
							if (idx == 0) idx = 12;
							else idx--;
						} while (players[(round + 1) % 2].GetRank(idx) != -1);


						if (idx <= 5) gotoxy(arrow_x, 14 + idx);
						else gotoxy(arrow_x, 16 + idx);
						if (round % 2 == 1) cout << "→";
						else cout << "←";

						break;
					case KEY_DOWN:
						if (idx <= 5) gotoxy(arrow_x, 14 + idx);
						else gotoxy(arrow_x, 16 + idx);
						cout << " ";
						do {
							if (idx == 12) idx = 0;
							else idx++;
						} while (players[(round + 1) % 2].GetRank(idx) != -1);

						if (idx <= 5) gotoxy(arrow_x, 14 + idx);
						else gotoxy(arrow_x, 16 + idx);
						if (round % 2 == 1) cout << "→";
						else cout << "←";
						break;
					default:
						break;
					}
				}

				if (c == ENTER) {
					nf = true;
					gotoxy(arrow_x, 14 + idx);
					cout << " ";
				}

			}
		}
		players[(round + 1) % 2].SetRank(idx, dice->GetDiceRank(idx));
		delete dice;
	}
	for (int i = 4; i < 8; i++) clearY(i);
	gotoxy(48, 4);
	if (players[0].GetRank(15) > players[1].GetRank(15)) cout << players[0].GetName() << " Win!!                      ";
	else if (players[0].GetRank(15) < players[1].GetRank(15)) cout << players[1].GetName() << " Win!!                   ";
	else cout << "What!!!!!! nani D R A W zzzz";


	gotoxy(48, 6);
	cout << "Press ENTER to go home";
	int c = 0;
	while (true) {
		if (_kbhit()) {
			c = _getch();
			if (c == ENTER) break;
		}
	}

	system("mode con:cols=130 lines=40 && color 0F");
	return 0;
	}
	else if (game_type == 2) {
		// online
		system("mode con:cols=130 lines=40");
		string player_name;
		WSADATA wsaData;
		SOCKET serverSock;
		SOCKADDR_IN serverAddr;
		string serverIPIn;
		int checkByte, len, usr_idx;
		char buf[BUFSIZE];
		
		ZeroMemory((void*)&buf, BUFSIZE);

		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
			ErrorHandling("WSAStartup() error!");

		serverSock = socket(PF_INET, SOCK_STREAM, 0);

		if (serverSock == INVALID_SOCKET)
			ErrorHandling("socket() error");

		gotoxy(45, 5);
		cout << "Host IP: ";
		cin >> serverIPIn;
		const char* serverIP = serverIPIn.c_str();
		ZeroMemory((void*)&serverAddr, sizeof(serverAddr));
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_port = htons(PORT);
		if (InetPton(AF_INET, serverIP, &serverAddr.sin_addr) != 1)
			ErrorHandling("Cannot Convert IP address");
		
		if (connect(serverSock, (const sockaddr*)&serverAddr, sizeof(serverAddr)) == INVALID_SOCKET)
			ErrorHandling("connect() error");


		checkByte = recv(serverSock, buf, BUFSIZE - 1 , 0);
		
		if (checkByte == SOCKET_ERROR)
			ErrorHandling("recv() error");
		else if (checkByte >= 0) {
			
				buf[checkByte] = '\0';
		}
		usr_idx = int(buf[0]) - 1;

		gotoxy(45, 5);
		cout << "Name of Player:   ";
		cin >> player_name;
		player_name.resize(20);

		checkByte = send(serverSock, player_name.c_str(), BUFSIZE - 1, 0);
		if (checkByte == SOCKET_ERROR)
			ErrorHandling("send() error");

		if (usr_idx==0){
			
			players[0].SetPlayer(0, player_name);
			checkByte = recv(serverSock, buf, BUFSIZE - 1 , 0);
			if (checkByte == SOCKET_ERROR)
				ErrorHandling("recv() error");
			else if (checkByte >= 0) {
				buf[checkByte] = '\0';
			}
			players[1].SetPlayer(1, string(buf));

			
		}
		else if (usr_idx == 1){
			players[1].SetPlayer(1, player_name);
			checkByte = recv(serverSock, buf, BUFSIZE - 1 , 0);
			if (checkByte == SOCKET_ERROR)
				ErrorHandling("recv() error");
			else if (checkByte >= 0) {
				buf[checkByte] = '\0';
			}
			players[0].SetPlayer(0, string(buf));
		}
		
		for (int round = 1; round <= 26; round++) { // odd round : 1p, even round : 2p
			Dice* dice = new Dice();
			ZeroMemory((void*)&buf, BUFSIZE - 1);
			SetGameInterface(players, *dice, round);
			cin.clear();
			
			if((round+1)%2 == usr_idx){ // this player's turn
				for (int attempt = 3; attempt > 0; attempt--) {
					int idx = 0;
					int c = 0;
					bool nf = false; // raise when enter key is pressed 
					
					dice->RollDice(serverSock);
					
					cin.clear();
					gotoxy(51, 4);
					cout << attempt - 1 << " reload(s) left";
					gotoxy(36, 5);
					cout << "Select dices to freeze and press ENTER to reroll";
					while (!nf) {
						if (_kbhit()) {
							c = _getch();
							if (c == 224 || c == 0) {
								switch ((c = _getch())) {
								case KEY_LEFT:
									gotoxy(50 + 5 * idx, 10);
									cout << " ";
									do {
										if (idx == 0) idx = 4;
										else idx--;

									} while (dice->isDiceFrozen(idx));
									gotoxy(50 + 5 * idx, 10);
									cout << "↓";

									break;
								case KEY_RIGHT:
									gotoxy(50 + 5 * idx, 10);
									cout << " ";
									do {
										if (idx == 4) idx = 0;
										else idx++;

									} while (dice->isDiceFrozen(idx));
									gotoxy(50 + 5 * idx, 10);
									cout << "↓";
									break;
								case KEY_UP:
									dice->SetDiceChangeable(idx, false);
									cin.clear();
									break;
								case KEY_DOWN:
									dice->SetDiceChangeable(idx, true);
									cin.clear();
									break;
								default:
									break;
								}
							}

							if (c == ENTER) {
								nf = true;
								gotoxy(50 + 5 * idx, 10);
								cout << " ";
								for (int i = 0; i < 5; i++) { 
									if (!dice->isDiceChangeable(i)) 
										dice->SetDiceFrozen(i);
									buf[i] = dice->isDiceFrozen(i);

									if (attempt == 0){
										dice->SetDiceFrozen(i);
										buf[i] = 1;
									}
									
									buf[5 + i] = (char)dice->GetFrozenIdx(i);
								}

								checkByte = send(serverSock, buf, BUFSIZE - 1 , 0);
								if (checkByte == SOCKET_ERROR)
									ErrorHandling("send() error");
								ZeroMemory((void*)&buf, BUFSIZE - 1);

							}

						}
					}
				}

				for (int i = 0; i < 5; i++) {
					if (dice->isDiceChangeable(i)) {
						dice->SetDiceChangeable(i, false);
					}
				}

				clearY(5);
				clearY(4);

				gotoxy(45, 6);
				cout << "    Select the rank to score   ";


				ScoreHelp();

				int idx = 0, c = 0, arrow_x;
				bool nf = false; // raise when enter key is pressed 
				while (players[(round + 1) % 2].GetRank(idx) != -1) idx++;

				if (round % 2 == 1) arrow_x = 38;
				else arrow_x = 78;
				cin.clear();
				while (!nf) {
					if (_kbhit()) {
						c = _getch();
						if (c == 224 || c == 0) {
							switch ((c = _getch())) {
							case KEY_UP:
								if (idx <= 5) gotoxy(arrow_x, 14 + idx);
								else gotoxy(arrow_x, 16 + idx);
								cout << " ";
								do {
									if (idx == 0) idx = 12;
									else idx--;
								} while (players[(round + 1) % 2].GetRank(idx) != -1);


								if (idx <= 5) gotoxy(arrow_x, 14 + idx);
								else gotoxy(arrow_x, 16 + idx);
								if (round % 2 == 1) cout << "→";
								else cout << "←";

								break;
							case KEY_DOWN:
								if (idx <= 5) gotoxy(arrow_x, 14 + idx);
								else gotoxy(arrow_x, 16 + idx);
								cout << " ";
								do {
									if (idx == 12) idx = 0;
									else idx++;
								} while (players[(round + 1) % 2].GetRank(idx) != -1);

								if (idx <= 5) gotoxy(arrow_x, 14 + idx);
								else gotoxy(arrow_x, 16 + idx);
								if (round % 2 == 1) cout << "→";
								else cout << "←";
								break;
							default:
								break;
							}
						}
						if (c == ENTER) {
							nf = true;
							gotoxy(arrow_x, 14 + idx);
							cout << " ";
						}

					}
				}
				buf[sizeof(int) * 0] = idx; // pack idx
				buf[sizeof(int) * 1] = dice->GetDiceRank(idx); // pack score
				checkByte = send(serverSock, buf, BUFSIZE - 1, 0);
				if (checkByte != BUFSIZE - 1)
					ErrorHandling("send() error");

				players[(round + 1) % 2].SetRank(idx, dice->GetDiceRank(idx));
				delete dice;
			}
			else { // other player's turn
				clearY(6);
				
				for (int attempt = 3; attempt > 0; attempt--) {
					gotoxy(43, 5);
					cout << "The other player is Rolling Dice";
					
					checkByte = recv(serverSock, buf, BUFSIZE - 1 , 0);
					if (checkByte == SOCKET_ERROR)
						ErrorHandling("recv() error");
					else if (checkByte >= 0) {
						buf[checkByte] = '\0';
					}
					dice->PrintfrozenDice();
					dice->RollDice(buf);
					gotoxy(43, 5);
					cout << "The other player is Freezing Dices";
					gotoxy(51, 4);
					cout << attempt - 1 << " reload(s) left";
					ZeroMemory((void*)&buf, BUFSIZE - 1);
					checkByte = recv(serverSock, buf, BUFSIZE - 1 , 0); 
					if (checkByte == SOCKET_ERROR)
						ErrorHandling("recv() error");
					else if (checkByte >= 0) {
						buf[checkByte] = '\0';
					}
					for (int i = 0; i < 5; i++) {
						for (int j = 0; j < 5; j++) {
							if (buf[j + 5] == i) {
								dice->SetDiceChangeable(j, false);
								dice->SetDiceFrozen(j);
								gotoxy(50 + 5 * j, 11);
								cout << " ";
							}
								
						}
						
					}
				}
				gotoxy(41, 5);
				cout << "The other player is Raking Scoreboard";
				ZeroMemory((void*)&buf, BUFSIZE - 1);
				checkByte = recv(serverSock, buf, BUFSIZE - 1, 0);
				if (checkByte == SOCKET_ERROR)
					ErrorHandling("recv() error");
				else if (checkByte >= 0) {
					buf[checkByte] = '\0';
				}

				if (usr_idx == 0) {
					players[1].SetRank(buf[0], buf[1 * sizeof(int)]);
				}
				else {
					players[0].SetRank(buf[0], buf[1 * sizeof(int)]);
				}
				
			}

			

		}
		for (int i = 4; i < 8; i++) clearY(i);
		gotoxy(48, 4);
		if (players[0].GetRank(15) > players[1].GetRank(15)) cout << players[0].GetName() << " Win!!                      ";
		else if (players[0].GetRank(15) < players[1].GetRank(15)) cout << players[1].GetName() << " Win!!                   ";
		else cout << "What!!!!!! nani D R A W zzzz";


		gotoxy(48, 6);
		cout << "Press ENTER to go home";
		int c = 0;
		while (true) {
			if (_kbhit()) {
				c = _getch();
				if (c == ENTER) break;
			}
		}

		checkByte = send(serverSock, "", BUFSIZE - 1, 0);
		if (checkByte == SOCKET_ERROR)
			ErrorHandling("send() error");

		closesocket(serverSock);
		WSACleanup();
		system("mode con:cols=130 lines=40 && color 0F");
		return 0;

		
	}
	else {
		// exception
		return 0;
	}
}

