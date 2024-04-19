#include <iostream>
#include <random>
#include "lib/UE4/UE_4.h"
using namespace std;

int main() {
    //Just for randomness -- Swap first with random index
    random_device rd;
    mt19937 gen(rd());

    // Definiere den Bereich für Zufallszahlen
    uniform_int_distribution<int> dis(0, 99); // Zufallszahlen von 0 bis 99

    // Größe des Arrays
    const int arraySize = 2000;

    // Array deklarieren und initialisieren
    int numbers[arraySize];

    // Array mit Zufallszahlen füllen
    for (int i = 0; i < arraySize; ++i) {
        numbers[i] = dis(gen);
    }

    MergeSort(numbers, 0, 1999);
    std::cout << findS(numbers, 2000, 120);




}

