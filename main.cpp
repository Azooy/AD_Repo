#include <iostream>
#include "src/lib/skiplist.h"
#include "src/lib/textsuche.h"
#include "random" 


using namespace std;



int main() {
    /*skiplist* newSkip = new skiplist;
    system("Pause");
    newSkip->init();
    newSkip->insert(10);
    newSkip->insert(13);
    newSkip->insert(12);
    newSkip->insert(15);
    newSkip->insert(27);
    newSkip->print();
    newSkip->deinit();
    newSkip->print();
    std::cout << " \n";
    system("Pause");*/
    char Text[]="ALGORITHMEN UND DATENSTRUKTUREN";
    char Muster[] = "DATEN";
    std::cout << boyerMoore(Text, 32, Muster, 5) << std::endl;
    system("Pause");


    

}