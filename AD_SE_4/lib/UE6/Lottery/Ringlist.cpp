//
// Created by jendrik on 29.04.2024.
//

#include "Ringlist.h"

void Ringlist::insert(int val_) {
    Element* elem = new Element(val_);
    if(head== nullptr){
        head = elem;
        tail = elem;
        elem->nextLink = head; // Pointer auf sich selbst für Ringstruktur
    } else {
        tail->nextLink = elem;
        tail = elem;
        elem->nextLink = head; // Fügt ein neues Element ans Ende der Linked List (nach dem Tail ein)
                               // Danach muss das neue Element noch als Tail deklariert werden
    }
}

void Ringlist::fill(){
    for(int i = 1; i <= 49; i++){   // Füllt die Ringliste mit den Lottozahlen von 1 - 49
        Ringlist::insert(i);
    }
}

void Ringlist::remove(int val_){
     Element* headTemp = head;
     Element* previous;
     while(headTemp->value != val_){
         previous = headTemp;
         headTemp = headTemp->nextLink;

         if(headTemp->nextLink == head){
             std::cout << "Link/Value not found -- terminating Removal-Process" << std::endl;
             return;
         }
     }
    if(headTemp->value == val_){
        previous->nextLink = headTemp->nextLink;
        delete headTemp;
        std::cout << "Remove";
        return;
    }


}

void Ringlist::printRing() {
    Element* temp = head;
    do{
        std::cout << temp->value << std::endl;
        temp = temp->nextLink;
    }while(temp != head);
}





