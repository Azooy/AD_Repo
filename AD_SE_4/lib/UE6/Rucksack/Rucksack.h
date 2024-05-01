//
// Created by Jendrik Juergens on 01.05.24.
//
#ifndef AD_SE_4_RUCKSACK_H
#define AD_SE_4_RUCKSACK_H
#include "tuple"
#include "iostream"

class tuple_cl{
public:
    double val;
    double weight;

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

#endif //AD_SE_4_RUCKSACK_H
