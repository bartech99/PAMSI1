#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void mergesort_h(int* tab, int start, int middle, int end)
{
    int* temp = new int[end - start + 1];
    int k = 0, i = start, j = middle + 1;

    while (i <= middle && j <= end)
    {
        if (tab[i] <= tab[j])
        {
            temp[k] = tab[i];
            ++i;
        }

        else 
        {
            temp[k] = tab[j];
            ++j;
        }
        ++k;
    }

    while (i <= middle)
    {
        temp[k] = tab[i];
        ++i;
        ++k;
    }

    while (j <= end)
    {
        temp[k] = tab[j];
        ++j;
        ++k;
    }

    for (i = start; i <= end; i++) 
    {
        tab[i] = temp[i - start];
    }

    delete[] temp;
}

void mergesort(int* tab, int start, int end) 
{
    if (start < end)
    {
        int middle = start + (end - start) / 2;
        mergesort(tab, start, middle);
        mergesort(tab, middle + 1, end);
        mergesort_h(tab, start, middle, end);
    }
}