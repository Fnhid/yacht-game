// yacht.cpp : Defines the entry point for the application.
//
#pragma once
#include "main.h"

void setConsoleSize() {
	system("mode con:cols=200 lines=40");
}

void menu() {
	cout << "[ * Menu * ]" << endl;
	cout << "1. vs Player" << endl;
	cout << "2. vs COM" << endl;
	cout << "3. Exit" << endl;
}

void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

int main()
{

	SetConsoleTitle("Yacht Game!");
	setConsoleSize();
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
			game(2);

		case 3:
			cout << "bye" << endl;
			return 0;
		default:
			cout << "Wrong Option, Please enter the right option." << endl;

		}
	}
	
}
