#include <iostream>
#include "lib/UE6/Lottery/Ringlist.h"

using namespace std;



int main() {
    Ringlist* ring = new Ringlist();
    for(int i = 1; i<=49; i++){
        ring->insert(i);
    }
    ring->printRing();


}