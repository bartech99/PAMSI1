#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "array.h"
#include "algorithms.h"
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    Array arr;
    Algorithms alg;

    double sorting_perc[7] = { 0, 0.25, 0.5, 0.75, 0.95, 0.99, 0.997 }; //stopień posortowania elementów
    unsigned int sizes[5] = { 10000, 50000, 100000, 500000, 1000000 }; //rozmiary tablic
    
    arr.create(50); //arg: ilosc elementow
    arr.put_values(0.25); //arg: procent posortowania

    alg.quicksort(arr);
    
    arr.show();
    arr.remove();

    //arr.check(int(0.5 * 50)); //arg: ilosc elementow * procent posortowania






    /*
    for (unsigned int it_sizes = 0; it_sizes < 5; it_sizes++)
    {
        cout << endl << it_sizes+1 << ". Dla " << sizes[it_sizes] << " elementow tablicy" << endl;
        for (unsigned int it_perc = 0; it_perc < 7; it_perc++)
        {
            cout << endl << "\t" << it_perc+1 << ") Dla " << sorting_perc[it_perc] * 100.0 << "% posortowania wstepnego" << endl;
            for (unsigned int it_h = 0; it_h < 100; it_h++)
            {
                if (!it_h)
                    cout << "\t   Sredni czas: " << " [ms]" << endl;
            }
        }
    }
    */

    return 0;
}