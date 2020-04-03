#pragma once

class Array
{

	int* numbers;
	unsigned int size;

public:

	int* tab;
	int* tab_h;

	Array(int* = nullptr, int* = nullptr, unsigned int = 0);
	~Array();

	//metody
	void copy();
	void create(unsigned int);
	bool check(unsigned int);
	void remove();
	void put_values(double);
	void put_reversed();
	void show();
};