#pragma once
#include <ctime>

class Test
{
	clock_t start, final;

public:

	Test(clock_t = 0, clock_t = 0);
	~Test();

	double intro[100];
	double merge[100];
	double quick[100];

	void init();
	void begin();
	double end();
	void print_average();
};