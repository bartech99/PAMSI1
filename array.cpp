#include "array.h"
#include <iostream>
using namespace std;



Array::Array(int* p1, int* p2, unsigned int s)
{
	this->numbers = p1;
	this->tab = p2;
	this->size = s;
}

Array::~Array() 
{
	this->numbers = nullptr;
	this->tab = nullptr;
}



void Array::copy()
{
	for (unsigned int i = 0; i < size; i++)
	{
		this->tab[i] = this->numbers[i];
	}
}

void Array::create(unsigned int s)
{
	size = s;
	this->numbers = new int[s];
	this->tab = new int[s];
}

bool Array::check(unsigned int i)
{
	while (i--)
	{
		if (tab[i] < tab[i - 1])
		{
			cout << "Blad sortowania!" << endl;
			return true;
		}
	}
	return false;
}

void Array::remove()
{
	delete[] this->tab;
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
		cout << this->tab[i] << "\t";

		if (i % 10 == 9)
			cout << endl << endl;
	}
	cout << endl;
}

