#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void mergesort_h (int* tab, int start, int middle, int end)
{
    int* temp = new int[end-start+1];

    int i = start;
    int j = middle + 1;
    int k = 0;

    while (i <= middle && j <= end)
    {
        if (tab[j] < tab[i])
        {
            temp[k] = tab[j];
            j++;
        }
        else
        {
            temp[k] = tab[i];
            i++;
        }
        k++;
    }

    if (i <= middle)
    {
        while (i <= middle)
        {
            temp[k] = tab[i];
            i++;
            k++;
        }
    }
    else
    {
        while (j <= end)
        {
            temp[k] = tab[j];
            j++;
            k++;
        }
    }

    for (i = 0; i <= end - start; i++)
    {
        tab[start + i] = temp[i];
    }

    delete[] temp;
}

void mergesort (int* tab, int start, int end)
{
    int middle;

    if (start != end)
    {
        middle = (start + end) / 2;
        mergesort (tab, start, middle);
        mergesort (tab, middle + 1, end);
        mergesort_h (tab, start, middle, end);
    }
}