#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Introsort.h"
using namespace std;

void quicksort(int* tab, int start, int end) 
{
    if (start < end) 
    {
        int pivot = partition_tab(tab, start, end);
        quicksort(tab, start, pivot);
        quicksort(tab, pivot + 1, end);
    }
}

int rev_partition_tab(int* tab, int start, int end) 
{
    int pivot = tab[(end + start) / 2];
    int i = start - 1;
    int j = end + 1;

    while (1) 
    {
        do 
        {
            ++i;
        } while (tab[i] > pivot);

        do 
        {
            --j;
        } while (tab[j] < pivot);

        if (i >= j)
        {
            return j;
        }

        swap_tab(tab, i, j);
    }
}