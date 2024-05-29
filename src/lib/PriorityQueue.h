#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
#include <iostream>



class object{
public:
    int value;
    int priority; 
    object():value(0), priority(0){};
    object(int val_):value(val_), priority(0){};
    object(int val_, int priority_):value(val_), priority(priority_){};

};

class q{
    public:
    std::vector<object> queue;
    int length = queue.size();
    void insert(object);
    void extractMin();
    void decreaseKey(object, int, int);
    void updateLength();
    void printQ();


} ;

void insert(q&, object);
object extractMin(q&);
object getMin(q);
void decreaseKey(q&, int, int);
void quicksortQueue(q&, int, int);
void preparePartition_q(q&, int, int, int&);
void swapObjects(object&, object&);


#endif