#pragma once
#include <ctime>

class Test
{
	clock_t start, final;

public:

	Test(clock_t = 0, clock_t = 0);
	~Test();

	double results[100];

	void init();
	void begin();
	double end();
	double calc_average();
	void print(double);
};