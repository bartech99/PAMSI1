#include <iostream>
#include "array.h"
using namespace std;

int main()
{
    Array arr;
    double sorting_perc[6] = { 0.25, 0.5, 0.75, 0.95, 0.99, 0.997 }; //stopień posortowania elementów
    unsigned int sizes[5] = { 10000, 50000, 100000, 500000, 1000000 }; //rozmiary tablic

    arr.create(50);
    arr.put_values(0.5);
    //arr.put_reversed();
    arr.show();
    arr.remove();

    return 0;
}