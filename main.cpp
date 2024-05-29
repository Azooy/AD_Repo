#include <iostream>
#include "src/lib/skiplist.h"
#include "random" 


using namespace std;



int main() {
    skiplist* newSkip = new skiplist;
    newSkip->init();
    newSkip->insert(10);
    newSkip->insert(13);
    newSkip->insert(12);

    newSkip->deleteNode(12);
    std::cout << newSkip->search(13) << " " << newSkip->search(12) << " " << newSkip->search(13) << " " << newSkip->search(9);

    return 0;
    

}