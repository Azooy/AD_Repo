//
// Created by jendrik on 29.04.2024.
//

#include "LinkedList.h"
#include <stddef.h>
#include <iostream>

void printLinked(element* e1){
    while(e1->next != nullptr){
        std::cout << e1->value << " ";
        e1=e1->next;
    }
    std::cout << e1->value;
};
element* element::createElem(int value){
    element* newE = new element(value, NULL);
    this->next = newE;
    return newE;
}
void swapE(int& a, int& b){
    int helper = a;
    a = b;
    b = helper;
}
int countLinks(element* e1){ // For counting the length of the linked list;
    int counter=1;
    while(e1->next!= nullptr){
        counter++;
        e1 = e1->next;
    }
    return counter;
}
element* array_create(int size, element* head){ // For filling the array;
    element* array = new element[size];
    int i = 0;
    while(head->next!= nullptr){
        array[i] = *head;
        head = head->next;
        i++;
    }
    array[i] = *head;
    return array;
}
void preparePartition(element list[], int indexOfPivot, int lastIndexOfArray, int &p) {
    int pivot=list[indexOfPivot].value;
    p = indexOfPivot - 1;
    for(int i = indexOfPivot; i < lastIndexOfArray; i++){
        if(list[i].value <= pivot){
            p++;
            swapE(list[i].value, list[p].value);
        }
    }
    swapE(list[indexOfPivot].value, list[p].value);
}
void writeBack(element e1[], element* head){
    int index = 0;
    while(head->next != nullptr){
        head->value = e1[index].value;
        index++;
        head=head->next;
    }
    head->value = e1[index].value;
    delete e1;
}
void quicksort(element list[], int firstIndex, int lastIndex){
    int part;
    if(firstIndex < lastIndex){
        preparePartition(list, firstIndex, lastIndex, part);
        quicksort(list, firstIndex, part - 1);
        quicksort(list, part+1, lastIndex);
    }
}


/*
 * Run-Time Analyse:
 * Der Algorithmus besteht im wesentlich aus folgenden Kernelementen:
 *   1.) Zählen der Links in der Linked-List (Func: countLinks(), Laufzeit: n) => Optimierung mittels Laufvariable im Konstruktor möglich
 *   2.) Erstellen und befüllen eines Arrays in dem die Links gespeichert werden (Laufzeit: n, Zusätzlich benötigter Speicher: n * sizeof(element))
 *   3.) Sortieren des Arrays mittels QuickSort (Laufzeit: n*log(n))
 *   4.) Zurückschreiben der Werte in die Linked-List (Func: writeBack(), Laufzeit: n)
 *
 *   T(n) = n log(n) + 3n
 *   Speicherplatzanalyse: 2 (n * sizeof(element))
 */




