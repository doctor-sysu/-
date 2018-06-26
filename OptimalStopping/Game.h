#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>



class LuckyCorona
{
private:
	int count;      //��¼�ж����ֿ�����;
	int zero_count; //��¼���Ʋ����Ŀ��������
	int cost;       //��¼�ɱ�;
	int simulation_time;       //��¼��Ҫģ����ٴ�
	int idealearn;  //��¼����������룬������ﵽ������ֺ󣬼�����Ϸ����������С�ڵ�ǰ����
	double alpha;   //��������;
	std::vector<int> prize;  //��¼ÿһ�ֿ����Զ�Ӧ�Ľ���;
	std::vector<int> record;     //ͳ�ƶ��ģ������ÿ��λ��ֹͣ��Ϸ�Ĵ���
	std::vector<int> position;   //��¼���е�ģ��Ľ��
	int income;    //��¼��ǰ׬����Ǯ;
	double expected_income;  //��¼�ڵ�ǰ����ÿ��ת��ת�̵���������;
	double average_income;   //��¼ͳ��֮��õ���ƽ��ÿ����Ϸ��õ�����
	int getrand() const;  //����һ�����������ת��һ��ת��;
	void simulation(int &, int &);      //����һ����Ϸģ��;
	void initial();
	void algorithm();
	void output();
public:
	void start();
};
