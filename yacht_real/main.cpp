// yacht.cpp : Defines the entry point for the application.
//
#pragma once
#include "main.h"


void menu() {
	gotoxy(55, 18);
	cout << "[ * Menu * ]" << endl;
	gotoxy(52, 19);
	cout << "→  1. vs Player" << endl;
	gotoxy(55, 20);
	cout << "2. vs CPU" << endl;
	gotoxy(55, 21);
	cout << "3. Exit" << endl;
}

void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

int main()
{

	SetConsoleTitle("Yacht Game!");
	system("mode con:cols=130 lines=40");
	std::cout << R"(
 __      __                   __          __             ______                                     __ 
/  \    /  |                 /  |        /  |           /      \                                   /  |
$$  \  /$$/______    _______ $$ |____   _$$ |_         /$$$$$$  |  ______   _____  ____    ______  $$ |
 $$  \/$$//      \  /       |$$      \ / $$   |        $$ | _$$/  /      \ /     \/    \  /      \ $$ |
  $$  $$/ $$$$$$  |/$$$$$$$/ $$$$$$$  |$$$$$$/         $$ |/    | $$$$$$  |$$$$$$ $$$$  |/$$$$$$  |$$ |
   $$$$/  /    $$ |$$ |      $$ |  $$ |  $$ | __       $$ |$$$$ | /    $$ |$$ | $$ | $$ |$$    $$ |$$/ 
    $$ | /$$$$$$$ |$$ \_____ $$ |  $$ |  $$ |/  |      $$ \__$$ |/$$$$$$$ |$$ | $$ | $$ |$$$$$$$$/  __ 
    $$ | $$    $$ |$$       |$$ |  $$ |  $$  $$/       $$    $$/ $$    $$ |$$ | $$ | $$ |$$       |/  |
    $$/   $$$$$$$/  $$$$$$$/ $$/   $$/    $$$$/         $$$$$$/   $$$$$$$/ $$/  $$/  $$/  $$$$$$$/ $$/ 
 v 1.0                                                                                                      
                                                                                                       
                                                                                                       

	)";
	while (1) {

		menu();
		int idx = 0, c;
		bool nf = false;
		while (!nf) {
			if (_kbhit()) {
				c = _getch();
				if (c == 224 || c == 0) {
					switch ((c = _getch())) {
					case KEY_UP:
						gotoxy(52, 19 + idx);
						cout << " ";
						if (idx == 0) idx = 2;
						else idx--;
						gotoxy(52, 19 + idx);
						cout << "→";
						break;
					case KEY_DOWN:
						gotoxy(52, 19 + idx);
						cout << " ";
						if (idx == 2) idx = 0;
						else idx++;
						gotoxy(52, 19 + idx);
						cout << "→";
						break;
					default:
						break;
					}
				}
				else if (c == ENTER) {
					nf = true;
					cout << " ";
				}

			}
		}
		switch (idx) {
		case 0:
			game(1);
			break;
		case 1:
			cout << "vs Computer mode is now under dev." << endl;
			//game(2);
			break;

		case 2:
			cout << "bye" << endl;
			return 0;
		}

	}
}


