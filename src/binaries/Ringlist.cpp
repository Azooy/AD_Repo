//
// Created by jendrik on 29.04.2024.
//

#include "Ringlist.h"

Element::Element():value(0),nextLink(nullptr){};
Element::Element(int val_): value(val_), nextLink(nullptr){};
Element::Element(int val_, Element* nextLink_):value(val_), nextLink(nextLink_){};


void Ringlist::incrementNumOfElems() {
    numOfElems++;
}


void Ringlist::insert(int val_) {
    Element* elem = new Element(val_, NULL);
    Ringlist::incrementNumOfElems();
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

void Ringlist::fill(int begin, int end){
    for(int i = begin; i <= end; i++){   // Füllt die Ringliste mit den Lottozahlen von 1 - 49
        Ringlist::insert(i);
    }
}

void Ringlist::remove(int val_){
    Element* headTemp = head;
    Element* previous;
    for(int i = 1; i <= val_; i++){
        previous = headTemp;
        headTemp = headTemp->nextLink;
    }
        previous->nextLink = headTemp->nextLink;

    if(headTemp==head){
        head=headTemp->nextLink;
    }

    delete headTemp;
    Ringlist::numOfElems--;
    return;
}

void Ringlist::printRing() {
    Element* temp = head;
    do{
        std::cout << temp->value << std::endl;
        temp = temp->nextLink;
    }while(temp != head);
}

int Ringlist::draw(){
    const int range_from  = 1;
    const int range_to    = Ringlist::numOfElems;
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to);
    return distr(rand_dev);
}

int* Ringlist::drawLottery() {
    int* draws = new int[6];
    for(int i = 0; i < 6; i++){
        int v = draw();

        Ringlist::remove(v);
        draws[i] = v;
    }
    return draws;
}



