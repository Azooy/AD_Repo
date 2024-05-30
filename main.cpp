#include <iostream>
#include "src/lib/skiplist.h"
#include "random" 


using namespace std;

void foo(){
  std::cout << "dasdu9haj<sud92";
}


int main() {
    skiplist* newSkip = new skiplist;
    system("Pause");
    newSkip->init();
    newSkip->insert(10);
    newSkip->insert(13);
    newSkip->insert(12);
    newSkip->insert(15);
    newSkip->insert(27);
    foo();
    //delete newSkip;
    //newSkip->head->print();
    system("Pause");
    
    

    return 0;
    

}