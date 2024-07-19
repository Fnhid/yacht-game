// yacht.cpp : Defines the entry point for the application.
//
#pragma once
#include "main.h"


void menu() {
	gotoxy(55, 18);
	cout << "[ * Menu * ]" << endl;
	gotoxy(55, 19);
	cout << "1. vs Player" << endl;
	gotoxy(55, 20);
	cout << "2. vs CPU" << endl;
	gotoxy(55, 21);
	cout << "3. Exit" << endl;
	gotoxy(55, 22);
	cout << "> ";
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
 v 0.1                                                                                                      
                                                                                                       
                                                                                                       

	)";
	int select;
	
	while (1) {
		
		menu();
		cin >> select;
		switch (select) {
		case 1:
			game(1);
			break;
		case 2:
			cout << "vs Computer mode is now under dev." << endl;
			//game(2);
			break;

		case 3:
			cout << "bye" << endl;
			return 0;
		default:
			cout << "Wrong Option, Please enter the right option." << endl;

		}
	}
	
}
