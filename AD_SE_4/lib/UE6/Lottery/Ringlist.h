//
// Created by jendrik on 29.04.2024.
//

#ifndef AD_SE_4_RINGLIST_H
#define AD_SE_4_RINGLIST_H
#include "iostream"

class Element{
public:
    int value;
    Element* nextLink;

    Element(int val_): value(val_), nextLink(nullptr){

    }

};

class Ringlist {
public:
    Element* head;
    Element* tail;

void insert(int);
void fill();
void remove(int);
void printRing();
};




#endif //AD_SE_4_RINGLIST_H
