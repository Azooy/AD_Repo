#include "../lib/PriorityQueue.h"

inline void q::updateLength(){
    length = queue.size()-1;
}


void q::printQ(){
    for(int i = 0; i <= this->length; i++){
        std::cout << "(" <<this->queue.at(i).value << "," << this->queue.at(i).priority << ")" << " ";
    }
}

void swapObjects(object& o1, object& o2){
    object temp = o1;
    o1 = o2;
    o2 = temp;
}

void q::insert(object o){
    queue.push_back(o);
    updateLength();
}

void quicksortQueue(q& queueObject, int low, int high){
    int p;
    if(low < high){
        preparePartition_q(queueObject, low, high, p);
        quicksortQueue(queueObject, low, p-1);
        quicksortQueue(queueObject, p+1, high);
    }
}

/// @brief 
/// @param queueObject 
/// @param low is the index of the pivot
/// @param high is the end of the subvector
/// @param part for finding the right position of pivot element
/// @return 
void preparePartition_q(q& queueObject, int low, int high, int& part){
    part=low-1;;
    object pivot = queueObject.queue.at(low);
    for(int i = low; i <= high; i++){
        if(pivot.priority <= queueObject.queue.at(i).priority){
            part++;
            swapObjects(queueObject.queue.at(i), queueObject.queue.at(part));
        }
    }
    swapObjects(queueObject.queue.at(low), queueObject.queue.at(part));
}


/// @brief 
/// @param queueObject 
/// @param o 
/// Time Complexity: WC = O(n^2)
void insert(q& queueObject, object o){
    queueObject.insert(o);
    quicksortQueue(queueObject, 0, queueObject.length);
}


/// @brief 
/// @param queueObject 
/// @return 
/// Time Complexity: O(1)

object extractMin(q& queueObject){
    std::vector<object> temp;
    object o = queueObject.queue.at(0);
    for(int i = 1; i <= queueObject.length; i++){
        temp.push_back(queueObject.queue.at(i));
    }
    queueObject.queue = temp;
    queueObject.updateLength();
    return o;
}

/// @brief 
/// @param queueObject 
/// @return 
/// time Complexity: O(1);
object getMin(q queueObject){
    return queueObject.queue.at(0);
}


/// @brief 
/// @param queueObject 
/// @param position 
/// @param newValue 
/// Time-Complexity: BC=O(1); WC=O(n^2); AC=O(log n)
/// Memory Complexity: n
void decreaseKey(q& queueObject,int position, int newValue){
    if(position < 0 || position > queueObject.length){
        std::cout << "Position out of bounds -- Terminating function call";
        return;
    }
    if(position == 0){
        queueObject.queue.at(position).priority = newValue;
        return;
    }
    if(position == queueObject.length){
        queueObject.queue.at(position).priority = newValue;
        quicksortQueue(queueObject, 0, queueObject.length);
    }
    else {
        if(newValue > queueObject.queue.at(position-1).priority && \
        newValue < queueObject.queue.at(position+1).priority){
            queueObject.queue.at(position).priority = newValue;
        }
        else {
            queueObject.queue.at(position).priority = newValue;
            quicksortQueue(queueObject, 0, queueObject.length);
        }
    }
}