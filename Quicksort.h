#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void quicksort(int* tab, int p, int q)
{
    int v = tab[(p + q) / 2];
    int i, j, x;

    i = p;
    j = q;

    do
    {
        while (tab[i] < v)
        {
            i++;
        }

        while (tab[j] > v)
        {
            j--;
        }

        if (i <= j)
        {
            x = tab[i];
            tab[i] = tab[j];
            tab[j] = x;
            i++;
            j--;
        }
    } while (i <= j);

    if (j > p)
    {
        quicksort(tab, p, j);
    }

    if (i < q)
    {
        quicksort(tab, i, q);
    }
}