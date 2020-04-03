#pragma once
#include <iostream>
#include <math.h>
using namespace std;



void introsort_h(int* tab, int start, int end, int maxdepth);
void introsort(int* tab, int start, int end);
void insertion(int* tab, int start, int end);
void heapsort_h(int* tab, int size, int root);
void heapsort(int* tab, int start, int end);
void swap_tab(int* tab, int s1, int s2);
int partition_tab(int* tab, int start, int end);



void introsort_h(int* tab, int start, int end, int maxdepth) 
{
    int size = end - start + 1;

    if (size <= 16) 
    {
        insertion(tab, start, end);
    }

    else if (maxdepth == 0) 
    {
        heapsort(tab, start, end);
    }

    else if (start < end) 
    {
        int pivot = partition_tab(tab, start, end);
        introsort_h(tab, start, pivot, --maxdepth);
        introsort_h(tab, pivot + 1, end, --maxdepth);
    }
}

void introsort(int* tab, int start, int end) 
{
    int maxdepth = (int)log(end - start + 1) * 2;
    introsort_h(tab, start, end, maxdepth);
}

void insertion(int* tab, int start, int end) 
{
    end++;
    int i = start;

    while (i < end) 
    {
        int j = i;

        while (j > 0 && tab[j - 1] > tab[j]) 
        {
            swap_tab(tab, j, j - 1);
            --j;
        }

        ++i;
    }
}

void heapsort_h(int* tab, int size, int root) 
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && tab[left] > tab[largest]) 
    {
        largest = left;
    }

    if (right < size && tab[right] > tab[largest]) 
    {
        largest = right;
    }

    if (largest != root) {
        swap_tab(tab, root, largest);
        heapsort_h(tab, size, largest);
    }
}

void heapsort(int* tab, int start, int end) 
{
    ++end;
    int* temp = new int[end - start];

    for (int i = 0; i < end - start; i++) 
    {
        temp[i] = tab[i + start];
    }

    for (int i = (end - start) / 2 - 1; i >= 0; --i) 
    {
        heapsort_h(temp, (end - start), i);
    }

    for (int i = (end - start) - 1; i >= 0; --i) 
    {
        swap_tab(temp, 0, i);
        heapsort_h(temp, i, 0);
    }

    for (int i = 0; i < end - start; i++) 
    {
        tab[i + start] = temp[i];
    }

    delete[] temp;
}

void swap_tab(int* tab, int s1, int s2) 
{
    int x = tab[s1];
    tab[s1] = tab[s2];
    tab[s2] = x;
}

int partition_tab(int* tab, int start, int end) 
{
    int pivot = tab[(end + start) / 2];
    int i = start - 1;
    int j = end + 1;
    while (1) 
    {
        do 
        {
            ++i;
        } while (tab[i] < pivot);

        do 
        {
            --j;
        } while (tab[j] > pivot);

        if (i >= j) 
        {
            return j;
        }

        swap_tab(tab, i, j);
    }
}