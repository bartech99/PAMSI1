#include "array.h"
#include "algorithms.h"
#include <iostream>
using namespace std;



Array::Array(int* p, unsigned int s)
{
	this->numbers = p;
	this->size = s;
}

Array::~Array() 
{
	this->numbers = nullptr;
}



void Array::create(unsigned int s)
{
	size = s;
	this->numbers = new int[s];
}

bool Array::check(unsigned int i)
{
	while (i--)
	{
		if (numbers[i] < numbers[i - 1])
		{
			cout << "Blad sortowania!" << endl;
			return true;
		}
	}
	return false;
}

void Array::remove()
{
	delete[] this->numbers;
}

void Array::put_values(double p)
{
	unsigned int pos = unsigned int(this->size * p);

	//czesc posortowana
	for (unsigned int i = 0; i < pos; i++)
	{
		this->numbers[i] = i+1;
	}

	//czesc losowa
	for (unsigned int i = pos; i < this->size; i++)
	{
		this->numbers[i] = pos + 1 + rand() % (this->size * 10);
	}
}

void Array::put_reversed()
{
	for (unsigned int i = 0; i < this->size; i++)
	{
		this->numbers[i] = this->size - i;
	}
}

void Array::show()
{
	for (unsigned int i = 0; i < this->size; i++)
	{
		cout << this->numbers[i] << "\t";

		if (i % 10 == 9)
			cout << endl << endl;
	}
}
