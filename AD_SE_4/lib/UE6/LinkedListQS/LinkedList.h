//
// Created by jendrik on 29.04.2024.
//

#ifndef AD_SE_4_LINKEDLIST_H
#define AD_SE_4_LINKEDLIST_H



class element{
public:
    int value;
    element* next;

    element* createElem(int);
};



void printLinked(element*);
void swapE(element*, element*);
int countLinks(element*);
element* array_create(int, element*);
void quicksort(element[], int, int);
void swapE(element&, element&);
void writeBack(element[], element*);

#endif //AD_SE_4_LINKEDLIST_H
