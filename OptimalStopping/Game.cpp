#include"Game.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

std::string getTime()
{
	time_t timep;
	time(&timep);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
	return tmp;
}

void LuckyCorona::initial()
{
	income = 0;
	expected_income = 0;
	average_income = 0;
	zero_count = 0;

	//welcome
	std::string time = getTime();
	std::cout << "----------------------------------------------------" << std::endl
		<< "Welcome to the lucky corna game!" << std::endl
		<< time << std::endl
		<< "----------------------------------------------------" << std::endl;

	std::cout << "Please enter the number of possible cases." << std::endl;
	std::cin >> count;
	std::cout << "Please enter each case's prize one by one." << std::endl
		<< "0 means you will exit the game with nothing." << std::endl;
	for (int i = 0; i < count; ++i)
	{
		int input;
		std::cin >> input;
		prize.push_back(input);
		if (!input)
			++zero_count;
	}
	std::cout << "Please enter the cost." << std::endl;
	std::cin >> cost;
	std::cout << "Please enter the discount factor." << std::endl;
	std::cin >> alpha;
	std::cout << "Please enter how many time you wish to simulate." << std::endl;
	std::cin >> simulation_time;
	std::cout << "----------------------------------------------" << std::endl
		<< "Initialization completed." << std::endl
		<< "Calculating....." << std::endl
		<< "----------------------------------------------------" << std::endl;

	for (int i = 0; i < count; ++i)
	{
		record.push_back(0);
		position.push_back(0);
	}
}


int LuckyCorona::getrand() const
{
	return rand() % count;          //返回的值是0到count-1范围内的任意一个整数
}


void LuckyCorona::simulation(int &earn, int &stoppoistion)
{
	int result = 0;
	earn = 0;
	stoppoistion = 0;

	//当继续游戏的期望收益大于当前收入的时候，继续游戏
	while ((expected_income + static_cast<double>(count - zero_count) / static_cast<double>(count) * static_cast<double>(earn) - cost) * alpha > static_cast<double>(earn))
	{
		result = getrand();
		++position[result];
		//如果破产
		if (prize[result] == 0)
		{
			earn = 0;
			break;
		}
		earn += prize[result];
	}
	stoppoistion = result;
}


void LuckyCorona::algorithm()
{
	int earn, stopposition;
	long double sum = 0;

	for (int i = 0; i < count; ++i)
		sum += prize[i];
	expected_income = sum / count;

	//ideal earn
	idealearn = (static_cast<double>(count) * alpha * (expected_income - static_cast<double>(cost))) / (static_cast<double>(count) - alpha * static_cast<double>(count - zero_count));

	for (int i = 0; i < simulation_time; ++i)
	{
		simulation(earn, stopposition);
		++record[stopposition];
		sum += earn;
	}
	//calculate avergae income
	average_income = sum / (static_cast<double>(simulation_time));
}


void LuckyCorona::output()
{
	std::cout << "Expected income each game is " << expected_income << "  ." << std::endl
		<< "The ideal income is " << idealearn << " ." << std::endl
		<< "After " << simulation_time << " simulations, the averaged income is " << average_income << "." << std::endl
		<< "And the specific data is listed below." << std::endl;
	for (int i = 0; i < count; ++i)
		std::cout << record[i] << " games stopped at situation " << i + 1 << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl
		<< "Game over!" << std::endl
		<< "-------------------------------------------------------" << std::endl;
}

void LuckyCorona::start()
{
	initial();
	algorithm();
	output();
}
