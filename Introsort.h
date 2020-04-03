#pragma once
#include <iostream>
#include <math.h>
using namespace std;

void introsort_h (int* tab, int first, int last, int depth);
void introsort (int* tab, int size);
int partition (int* tab, int first, int last);
void insertion (int* tab, int size);
void swap (int* a, int* b);
void heap_h (int* tab, int start, int end);
void heapsort (int* tab, int start, int end);
bool check (int* tab, int end);



void introsort_h (int* tab, int first, int last, int depth) 
{
	while (last - first > 0)
	{
		if (depth == 0)
		{
			heapsort (&tab[first], first, last - first + 1);
		}
		else 
		{
			int pivot;

			if (check(tab, last))
			{
				break;
			}

			pivot = partition (tab, first, last);
			introsort_h (tab, pivot + 1, last, depth - 1);
			last = pivot - 1;
		}
	}
}

void introsort (int* tab, int size)
{
	introsort_h (tab, 0, size - 1, (int(2 * log(double(size)))));
	insertion (tab, size);
}

int partition (int* tab, int first, int last) 
{
	int pivot;
	int mid = (first + last) / 2;

	pivot = tab[first] > tab[mid] ? first : mid;

	if (tab[pivot] > tab[last])
	{
		pivot = last;
	}

	swap (tab[pivot], tab[first]);
	pivot = first;

	while (first < last) 
	{
		if (tab[first] <= tab[last])
		{
			swap (tab[pivot++], tab[first]);
		}
		++first;
	}

	swap (tab[pivot], tab[last]);
	return pivot;
}

void insertion (int* tab, int size)
{
	int i;

	for (i = 1; i < size; i++)
	{
		int j;
		int temp = tab[i];

		for (j = i; j >= 1 && tab[j - 1] > temp; j--)
		{
			tab[j] = tab[j - 1];
		}

		tab[j] = temp;
	}
}

void swap (int *a, int *b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heap_h (int* tab, int start, int end)
{
	int temp = tab[start];

	while (start <= end / 2) 
	{
		int k = 2 * start;
		while (k < end && tab[k] < tab[k + 1])
		{
			++k;
		}

		if (temp >= tab[k])
		{
			break;
		}

		tab[start] = tab[k];
		start = k;
	}

	tab[start] = temp;
}

void heapsort (int *tab, int start, int end)
{
	int* temp = new int[end-start+1];
	for (int i = 0; i < end - start; i++)
	{
		temp[i] = tab[start + i];
	}

	for (int i = (end - 1) / 2; i >= start; i--) 
	{
		heap_h (temp, i, end - 1);
	}

	for (int i = end - 1; i > start; i--) 
	{
		swap (temp[i], temp[start]);
		heap_h (temp, start, i - 1);
	}

	for (int i = 0; i < end - start; i++)
	{
		tab[start + i] = temp[i];
	}
}

bool check (int* tab, int end) 
{
	for (int i = 0; i < end; i++) 
	{
		if (tab[i] > tab[i + 1]) 
		{
			return false;
		}
		else 
		{
			return true;
		}
	}
	return true;
}