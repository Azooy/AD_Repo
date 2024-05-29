#include "../lib/skiplist.h"

void skiplist::deleteNode(int key){
    skiplistNode* current = head;
    head->deleteNode(key);

}

void skiplistNode::deleteNode(int key){
    skiplistNode* current = this;
    skiplistNode* destNode;
    std::vector<skiplistNode*> update_vector(MAXHEIGHT, nullptr);
    // find predecessor 
    for(int i = MAXHEIGHT-1; i >= 0; i--){
        while(current->forward.at(i)->value < key && current->forward.at(i) != nullptr){
            if(current->forward.at(i)->value == key){
                update_vector.at(i) = current;
                destNode = current->forward.at(i);
                } else {
                    current = current->forward.at(i);
                }
            }
        }
    
    for(int i = 0; i < MAXHEIGHT; i++){
        if(update_vector.at(i) != nullptr){
        update_vector.at(i) = destNode->forward.at(i);
        } 
        break;
    }

        delete destNode;
    
    }


bool skiplist::search(int key){
    skiplistNode* current = head;
    for(int i = MAXHEIGHT-1; i >= 0; i--){
        while(key >= current->forward.at(i)->value && current->forward.at(i) != nullptr){
            if(current->forward.at(i)->value == key){
                return true;
            } else {
                current = current->forward.at(i);
            }
        }
    }
    return false;
}

void skiplist::init(){
    skiplistNode* tail = new skiplistNode; // set value to -inf
    head->value = INT32_MIN;
    tail->value = INT32_MAX; // set value to inf
    head->forward.resize(MAXHEIGHT, tail); // head and tail from 0 to 3
    tail->forward.resize(MAXHEIGHT, nullptr);
};

void skiplist::insert(int key){
    head->insert(key);
}

void skiplistNode::insert(int key){
    int newLevel = 0; 
    skiplistNode* current = this;
    std::vector<skiplistNode*> update_vector(MAXHEIGHT, nullptr);
    while (newLevel < MAXHEIGHT && (rand() % 2) == 1) // here rand()%2 is doing the coin toss
    {
        newLevel++;
    } 

    for(int i = MAXHEIGHT-1; i >= 0; i--){
        while(current->forward.at(i)->value < key && current->forward.at(i) != nullptr){
            current = current->forward.at(i);
        }
        update_vector.at(i) = current; // Store the "pass through"
    }

    // Create Node
    skiplistNode* newNode = new skiplistNode;
    newNode->height = newLevel+1;
    newNode->value = key;
    newNode->forward.resize(newLevel+1, nullptr);

    for(int i = 0; i < newNode->height; i++){ // connect newNode forwards
       // In the update_vector the pointers to the node-object is stored, need to get the correct position in tower
        newNode->forward.at(i) = update_vector.at(i)->forward.at(i); 
        update_vector.at(i)->forward.at(i) = newNode;
    }
    



};
