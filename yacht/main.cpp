// yacht.cpp : Defines the entry point for the application.
//

#include "main.h"

void setConsoleSize() {
	system("mode con:cols=200 lines=40");
}

void menu() {
	cout << "[ * Menu * ]" << endl;
	cout << "1. Play" << endl;
	cout << "2. Exit" << endl;
}

void setColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

int main()
{

	SetConsoleTitle("Yacht Game!");
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
	int select, players_num;
	setConsoleSize();
	
	while (1) {
		system("mode con:cols=200 lines=40");
		menu();
		cin >> select;
		switch (select) {
		case 1:
			game();
			break;		
		case 2:
			cout << "bye" << endl;
			return 0;
		default:
			cout << "Wrong Option, Please enter the right option." << endl;

		
	}
	
}
