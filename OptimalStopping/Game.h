#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>



class LuckyCorona
{
private:
	int count;      //记录有多少种可能性;
	int zero_count; //记录“破产”的可能情况数
	int cost;       //记录成本;
	int simulation_time;       //记录需要模拟多少次
	int idealearn;  //记录最理想的收入，即收益达到这个数字后，继续游戏的期望收益小于当前收益
	double alpha;   //折现因子;
	std::vector<int> prize;  //记录每一种可能性对应的奖励;
	std::vector<int> record;     //统计多次模拟中在每个位置停止游戏的次数
	std::vector<int> position;   //记录所有的模拟的结果
	int income;    //记录当前赚到的钱;
	double expected_income;  //记录在当前局中每次转动转盘的期望收益;
	double average_income;   //记录统计之后得到的平均每次游戏获得的收入
	int getrand() const;  //产生一个随机数，即转动一次转盘;
	void simulation(int &, int &);      //进行一次游戏模拟;
	void initial();
	void algorithm();
	void output();
public:
	void start();
};
