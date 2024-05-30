#ifndef SKIPLIST_H
#define SKIPLIST_H
#include <vector>
#include <random>
#include <limits.h>
#include <iostream>
#define MAXHEIGHT 4

class skiplist;


class skiplistNode{
public:
    int value;
    int height;
    std::vector<skiplistNode*> forward;

    skiplistNode():value(0), height(MAXHEIGHT){};
    ~skiplistNode(){
        forward.clear();
    }

    void insert(int);
    bool search(int);
    void deleteNode(int);
    void print();
    void deinit(skiplist*);
    int findPosition(int);
 
};

class skiplist{
public:
    int maxHeight = MAXHEIGHT+1;
    int nodeCount = 0;
    skiplistNode* head = new skiplistNode;

    // Methods 
    bool search(int);
    void insert(int);
    void deleteNode(int);
    void print();
    void init();
    void deinit();
    

    ~skiplist(){
      head->deinit(this);
    }
  
    friend class skiplistNode;
    
};

int randomNumberGenerator();

#endif