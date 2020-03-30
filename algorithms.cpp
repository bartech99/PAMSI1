#include "algorithms.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;



Algorithms::Algorithms(int* t, unsigned int s)
{
	this->tab = t;
	this->size = s;
}

Algorithms::~Algorithms()
{
	this->tab = nullptr;
}



void Algorithms::copy(Array& a)
{
	//kopiowanie
}

int Algorithms::quicksort()
{
	return 0;
}



int Algorithms::introsort()
{
	return 0;
}



int Algorithms::mergesort()
{
	return 0;
}
