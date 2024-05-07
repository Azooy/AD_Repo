//
// Created by Jendrik Juergens on 01.05.24.
//
#ifndef RUCKSACK_H
#define RUCKSACK_H
#include "tuple"
#include "iostream"

class tuple_cl{
public:
    double val;
    double weight;
    double ratio;

    tuple_cl();
    tuple_cl(double);
    tuple_cl(double, double);

    void print();
};

using namespace std;

void backpack(tuple_cl[], double, int);
void mergesort(tuple_cl[], int, int);
void merge(tuple_cl[], int, int, int);
double max_weight(tuple_cl[], int, int);
void printarray(tuple_cl[], int);


/*
Variante 2 mit a(i) ist 1 oder 0 ist dann schlecht, wenn der Rucksack nicht komplett gefüllt werden kann
weil die verbleibenden Objekte mehr als die Restkapazität vom Rucksack wiegen.
Ausserdem kann die Value-To-Weight-Ratio für Objekte mit dem Value / Weight = 0; nicht gut eingeordnet werden. Es werden
also nur die Objekte berücksichtigt die überhaupt einen Wert haben. (Sortierung u.U. nicht korrekt).

*/

#endif //AD_SE_4_RUCKSACK_H
