#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "array.h"
#include "test.h"
#include "Introsort.h"
#include "Mergesort.h"
#include "Quicksort.h"
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    Array arr;
    Test test;

    double sorting_perc[7] = { 0, 0.25, 0.5, 0.75, 0.95, 0.99, 0.997 }; //stopień posortowania elementów
    unsigned int sizes[5] = { 10000, 50000, 100000, 500000, 1000000 }; //rozmiary tablic
    test.init();
    /*
    for (unsigned int it_sizes = 0; it_sizes < 5; it_sizes++)
    {
        cout << it_sizes+1 << ". Dla " << sizes[it_sizes] << " elementow tablicy" << endl;
        for (unsigned int it_perc = 0; it_perc < 7; it_perc++)
        {
            cout << endl << "\t" << it_perc+1 << ") Dla " << sorting_perc[it_perc] * 100.0 << "% posortowania wstepnego" << endl;

            for (unsigned int it_h = 0; it_h < 100; it_h++)
            {
                arr.create(sizes[it_sizes]); //arg: ilosc elementow
                arr.put_values(sorting_perc[it_perc]); //arg: procent posortowania

                arr.copy();
                test.begin();
                quicksort(arr.tab, 0, sizes[it_sizes]-1);
                test.quick[it_h] = test.end();
                arr.check(sizes[it_sizes]);
                
                arr.copy();
                test.begin();
                introsort(arr);
                test.intro[it_h] = test.end();
                //arr.check(sizes[it_sizes]);

                arr.copy();
                test.begin();
                mergesort(arr);
                test.merge[it_h] = test.end();
                //arr.check(sizes[it_sizes]);
                
                arr.remove();
            }

            test.print_average();
        }
        cout << endl;
    }
    */


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///Strefa testowania algorytmu
    
    arr.create(10); //arg: ilosc elementow
    arr.put_values(0.0); //arg: procent posortowania
    arr.copy();

    arr.show();
    cout << endl << endl;

    //introsort(arr);
    //mergesort(arr);

    arr.show();

    arr.remove();
    
    return 0;
}