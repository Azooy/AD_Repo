#include "../lib/Hashing.h"
#include <iostream>

    int Hashtable::quadratic(int key, int i){
        int index_of_Hashing = hashFunction(key);
        return index_of_Hashing + (C1*i) + (C2*i*i);
    }


    void Hashtable::insert_linearProbing(int key)
    {
        int index_of_Hashing = hashFunction(key);
        while(HashTable[index_of_Hashing] != NULL){
            index_of_Hashing++;
        }
        HashTable[index_of_Hashing] = key;
    }



    void Hashtable::insert_quadraticProbing(int key){
        int index_of_Hashing = hashFunction(key);
        int i = 0;
        while(HashTable[index_of_Hashing]!= NULL){
            index_of_Hashing = quadratic(key, i) % HashSize;
            i++;
        }
        HashTable[index_of_Hashing] = key;
    };

   void Hashtable::insert_doubleHashing(int key){
    int index_of_Hashing = hashFunction(key);
    int i = 0;
    int scnd_Index;
    while(HashTable[index_of_Hashing]!= NULL){
        scnd_Index = scndHash(key);
        index_of_Hashing = (index_of_Hashing + i*scnd_Index) % HashSize;
        i++;
    }
    HashTable[index_of_Hashing] = key;
   };

   void Hashtable::display(){
    for(int i = 0; i < HashSize; i++){
        std::cout << i << " | " << HashTable[i] << std::endl;
    }
   }