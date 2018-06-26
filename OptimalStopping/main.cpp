#include"Game.h"
#include <string>
#include <ctime>
#include <iostream>

int main()
{
	srand(time(NULL));
	bool is_continue = true;;

	while (is_continue) {
		LuckyCorona Game;
		Game.start();
		std::cout << "Enter 0 to exit, other to continue." << std::endl;
		std::cin >> is_continue;;;
	}
	std::cout << "Have a nice day!" << std::endl;
	return 0;
}
