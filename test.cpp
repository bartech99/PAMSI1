#include "test.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void Test::init()
{
	srand(static_cast<unsigned int>(time(NULL)));
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

void Test::print_average()
{
	double avg_quick = 0.0;
	double avg_intro = 0.0;
	double avg_merge = 0.0;

	for (unsigned int i = 0; i < 100; i++)
	{
		avg_merge += merge[i];
		avg_quick += quick[i];
		avg_intro += intro[i];
	}

	avg_merge = avg_merge / 100.0;
	avg_quick = avg_quick / 100.0;
	avg_intro = avg_intro / 100.0;

	cout << "\t   Szybkie sortowanie: \t\t" << avg_quick*1000.0 << " [ms]" << endl;
	cout << "\t   Sortowanie introspektywne: \t" << avg_intro*1000.0 << " [ms]" << endl;
	cout << "\t   Sortowanie przez scalanie: \t" << avg_merge*1000.0 << " [ms]" << endl;
}



Test::Test(clock_t s, clock_t f, int a, int b, int c)
{
	start = s;
	final = f;
	for (int i = 0; i < 100; i++)
	{
		merge[i] = a;
		quick[i] = b;
		intro[i] = c;
	}
}

Test::~Test() {}