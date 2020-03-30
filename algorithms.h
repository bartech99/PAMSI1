#pragma once
#include "Array.h"
class Algorithms
{
	int* tab;
	unsigned int size;

public:

	Algorithms(int* = nullptr, unsigned int = 0);
	~Algorithms();

	//metody
	void copy(Array&);
	int quicksort();
	int introsort();
	int mergesort();
};