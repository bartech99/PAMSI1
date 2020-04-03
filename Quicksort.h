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