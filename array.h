#pragma once

class Array
{
	int* numbers;
	unsigned int size;

public:

	Array(int* = nullptr, unsigned int = 0);
	~Array();

	//metody
	void create(unsigned int);
	void remove();
	void put_values(double);
	void put_reversed();
	void show();
};