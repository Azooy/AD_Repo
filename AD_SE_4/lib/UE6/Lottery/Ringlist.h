//
// Created by jendrik on 29.04.2024.
//

#ifndef AD_SE_4_RINGLIST_H
#define AD_SE_4_RINGLIST_H
#include "iostream"
#include "random"

class Ringlist;

class Element{
public:
    int value;
    Element* nextLink;


    Element();
    explicit Element(int val_);
    Element(int val_, Element* nextLink_);
};



class Ringlist {
public:
    Element* head;
    Element* tail;
    int numOfElems = 0;

void insert(int);
void fill(int,int);
void remove(int);
void printRing();
void incrementNumOfElems();
int draw();
int* drawLottery();

};




#endif //AD_SE_4_RINGLIST_H
