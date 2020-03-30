#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "array.h"
#include "algorithms.h"
#include "test.h"
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    Array arr;
    Algorithms alg;
    Test test;

    double sorting_perc[7] = { 0, 0.25, 0.5, 0.75, 0.95, 0.99, 0.997 }; //stopień posortowania elementów
    unsigned int sizes[5] = { 10000, 50000, 100000, 500000, 1000000 }; //rozmiary tablic
    test.init();
    /*
    test.begin();
    for (unsigned int it_sizes = 0; it_sizes < 5; it_sizes++)//dopisać tworzenie i usuwanie tablic oraz wywołania algorytmów
    {
        cout << it_sizes+1 << ". Dla " << sizes[it_sizes] << " elementow tablicy" << endl;
        for (unsigned int it_perc = 0; it_perc < 7; it_perc++)
        {
            cout << endl << "\t" << it_perc+1 << ") Dla " << sorting_perc[it_perc] * 100.0 << "% posortowania wstepnego" << endl;
            for (unsigned int it_h = 0; it_h < 100; it_h++)
            {
                if (!it_h)
                {
                    cout << "\t   Szybkie sortowanie: \t\t" << " [s]" << endl;
                    cout << "\t   Sortowanie introspektywne: \t" << " [s]" << endl;
                    cout << "\t   Sortowanie przez scalanie: \t" << " [s]" << endl;
                }
            }
        }
        cout << endl;
    }
    test.results[0] = test.end();
    test.print(test.calc_average());
    */
    



    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///Strefa testowania algorytmu

    arr.create(50); //arg: ilosc elementow
    arr.put_values(0.25); //arg: procent posortowania
    //arr.check(int(0.5 * 50)); //arg: ilosc elementow * procent posortowania

    alg.copy(arr);
    alg.quicksort();
    //alg.introsort();
    //alg.mergesort();

    arr.show();
    arr.remove();

    return 0;
}