#include <iostream>
#include <random>
#include "algorithm"
#include "chrono"
#include "lib/UE4/UE4_2.h"

using namespace std;

int main() {
    //Just for randomness -- Swap first with random index
    random_device rd;
    std::default_random_engine rng(rd());
    std::vector<int> numbers(50'000'000);
    for(int a=0; a < 50'000'000; a++){
        numbers[a] = a;
    }

    shuffle(numbers.begin(), numbers.end(), rng);


    auto start = std::chrono::high_resolution_clock::now();
    MergeSort_Vec(numbers, 0, 50'000'000);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    cout << "Vergangene Zeit :" << elapsed_seconds.count() << " Sekunden" << endl;


    return 0;

    /*
     * Bubblesort: 105.000 Elemente, 60,75 Sekunden
     * Quicksort: 150.000.000 Elemente, 58,03 Sekunden
     * Mergesort: 50.000.000 Elemente, 63,60 Sekunden
     */



}

