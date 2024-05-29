#ifndef SKIPLIST_H
#define SKIPLIST_H
#include <vector>
#include <random>
#include <limits.h>
#define MAXHEIGHT 4




class skiplistNode{
public:
    int value;
    int height;
    std::vector<skiplistNode*> forward;

    skiplistNode():value(0), height(MAXHEIGHT){};

    void insert(int);
    void search(int);
    void deleteNode(int);
    
};




class skiplist{
public:
    int maxHeight = MAXHEIGHT+1;
    skiplistNode* head = new skiplistNode;

    // Methods 
    bool search(int);
    void insert(int);
    void deleteNode(int);
    void print();
    void init();
};


#endif