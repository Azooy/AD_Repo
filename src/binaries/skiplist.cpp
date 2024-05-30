#include "../lib/skiplist.h"


int skiplistNode::findPosition(int key){
    skiplistNode* current = this;
    int position = 0;
    bool flag;
    if(current->search(key)){
      while(current->value < key && current->forward.at(0) != nullptr){
        position++;
        current = current->forward.at(0);
      }
      return position;
    } else {
      return -1;
    }
}


void skiplist::print(){
  skiplistNode* current = head;
  current->print();
  std::cout << std::endl;
}



void skiplistNode::print(){
    skiplistNode* head = this;
    skiplistNode* current = this;
    for(int i = MAXHEIGHT-1; i >= 0; i--){
      int position=0;
      while(current->value <= INT32_MAX){
        position = head->findPosition(current->value);
        for(int i = 0; i < position; i++){
          std::cout << "-";
        }
        std::cout << "" << "[" << current->value << "]";
        if(current->forward.at(i) != nullptr){
          current = current->forward.at(i);
        } else{
          break;
        }
      }
        current = head;
        std::cout << std::endl;
      }
        /*if(current->forward.at(i)->value == INT32_MAX){
          std::cout << "[" << current->value << "]";
          for(int i = 0; i <= nodeCount; i++){
            std::cout << "-------";
          }
          std::cout << ">[" << current->forward.at(i)->value << "]";
          break;
        } else {
          
          std::cout << "[" << current->value << "]";
          std::cout << "-->";
          nodeCount--;
          current = current->forward.at(i);
        }
      }
      std::cout << std::endl;
      nodeCount = skip.nodeCount;
      current = temp;
    }*/


    

}


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
        while(current->forward.at(i)->value <= key && current->forward.at(i) != nullptr){
            if(current->forward.at(i)->value == key){
                update_vector.at(i) = current;
                destNode = current->forward.at(i);
                break;
                } else 
                  current = current->forward.at(i);
            }
        }
    
    for(int i = 0; i < MAXHEIGHT; i++){
        if(update_vector.at(i) != nullptr){
        update_vector.at(i)->forward.at(i) = destNode->forward.at(i);
        } else{
          break;
        }
        
    }

        delete destNode;
    
    }


bool skiplistNode::search(int key){
    skiplistNode* current = this;
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
    this->nodeCount++;
    head->insert(key);
}

void skiplistNode::insert(int key){
    int newLevel = 0; 
    skiplistNode* current = this;
    std::vector<skiplistNode*> update_vector(MAXHEIGHT, nullptr);
    while (newLevel < MAXHEIGHT-1 && (randomNumberGenerator()%2)) // here rand()%2 is doing the coin toss
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
    };
    
};

int randomNumberGenerator(){
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 128);
  int randomnr= dis(gen);
  int mod = randomnr;
  return mod;
}


void skiplist::deinit(){
  skiplistNode* current = head;
  skiplist* liste = this;
  current->deinit(liste);
  delete this;
}

void skiplistNode::deinit(skiplist* liste){
  skiplistNode* current = this;
  while(current->forward.at(0)!= nullptr){
    current = current->forward.at(0);
    current->deinit(liste);}
    forward.clear();

}
