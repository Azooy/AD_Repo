#ifndef HASHING_H
#define HASHING_H
#include <stdlib.h>

#define C1 1
#define C2 3 

enum collision {linear, quadratisch, double_hashing};

class Hashtable{
    static const int HashSize = 11;
    int HashTable[HashSize];

public:
    Hashtable() {
    for(int i = 0; i < HashSize; i++)
        HashTable[i] = NULL;};

    inline int hashFunction(int key){ return key % HashSize;}
    inline int scndHash(int key){return 1 + (key % (HashSize-1));}
    void insert_linearProbing(int);
    void insert_quadraticProbing(int);
    void insert_doubleHashing(int);
    void display();
    int quadratic(int, int);

};


#endif
