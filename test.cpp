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
	cout.precision(5);
	cout << "\t   Szybkie sortowanie: \t\t" << avg_quick << " [s]" << endl;
	cout << "\t   Sortowanie introspektywne: \t" << avg_intro << " [s]" << endl;
	cout << "\t   Sortowanie przez scalanie: \t" << avg_merge << " [s]" << endl;
	cout.precision(1);
}



Test::Test(clock_t s, clock_t f)
{
	start = s;
	final = f;
}

Test::~Test() {}
