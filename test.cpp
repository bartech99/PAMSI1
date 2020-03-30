#include "test.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void Test::init()
{
	cout.setf(ios::fixed);	
	cout.precision(1);
}

void Test::begin()
{
	start = clock();
}

double Test::end()
{
	final = clock();
	return (final - start) / (double)CLOCKS_PER_SEC;
}

double Test::calc_average()
{
	double temp = 0.0;
	for (unsigned int i = 0; i < 100; i++)
	{
		temp += results[i];
	}
	return temp/100.0;
}

void Test::print(double t)
{
	cout.precision(5);
	cout << "\t   Sredni czas: " << t << " [s]" << endl;
	cout.precision(1);
}



Test::Test(clock_t s, clock_t f)
{
	start = s;
	final = f;
	for (unsigned int i = 0; i < 100; i++)
	{
		results[i] = 0;
	}
}

Test::~Test() {}