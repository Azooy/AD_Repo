#include "../lib/BinarySearchTree.h"
#include "iostream"

Tree::Tree():val(0), left(nullptr), right(nullptr){};
Tree::Tree(int val_): val(val_), left(nullptr), right(nullptr){};
Tree::Tree(int val_, Tree* left_):val(val_), left(left_), right(nullptr){};
Tree::Tree(int val_, Tree* left_, Tree* right_): val(val_), left(left_), right(right_){};
Tree::~Tree(){
        this->val = NULL;
        this->left = nullptr;
        this->right = nullptr;
    };

Tree* Tree::findTreeNode(Tree* searched){
    Tree* root = this;
    if(searched->val < root->val){
        root = root->left;
        root = root->findTreeNode(searched);
    }
    if(searched->val > root->val){
        root = root->right;
        root = root->findTreeNode(searched);
    }
    if(searched->val != root->val && root->left == nullptr && root->right== nullptr){
        return nullptr;
    }
    if(searched->val == root->val){
        return root;
    }
}

void Tree::addTreeNode(Tree* newVal){
    Tree* currentNode = this;
    if(currentNode->val > newVal->val){
        if(currentNode->left==nullptr){
            currentNode->left = newVal;
        }
        currentNode = currentNode->left;
        currentNode->addTreeNode(newVal);
    }
    if(currentNode->val < newVal->val){
        if(currentNode->right==nullptr){
            currentNode->right = newVal;
        }
        currentNode = currentNode->right;
        currentNode->addTreeNode(newVal);
    }        
};

Tree* Tree::findPre(Tree* elementToFind){
    Tree* root;
    root = this;
    while(root->left->val != elementToFind->val && root->right->val != elementToFind->val)
        {
            if(elementToFind->val < this->val){
                root = root->left;
            }

            if(elementToFind->val > this->val){
                root = root->right;
            }
            
        }
    return root;

}

void Tree::deleteTreeNode(Tree* ToDelete){
    // Setup 
    Tree* currentNode = this;
    Tree* prev = this->findPre(ToDelete); // keep track on what the predecessor is
    bool isleft = prev->left->val == ToDelete->val ? 1 : 0;
    Tree* previous; 
    Tree* elem = currentNode->findTreeNode(ToDelete);
    Tree* temp = elem;


    if(elem->left == nullptr){ // No successor
        if(elem->right == nullptr){
            if(isleft){
                prev->left = nullptr;
            } else {
                prev->right = nullptr;
            }

            delete elem;
            return;
        }
    }

    if(elem->left != nullptr){ // left successor but no right successor
        if(elem->right == nullptr){
            if(isleft){
                prev->left = nullptr;
            } else {
                prev->right = nullptr;
            }
            prev->left = elem->left;
            delete elem;
            return;
        }
    }

    if(elem->right != nullptr){ // right successor but no left successor
        if(elem->left == nullptr){
            if(isleft){
                    prev->left = nullptr;
                } else {
                    prev->right = nullptr;
                }
            prev->right = elem->right;
            delete elem;
            return;
        }
    }
    previous = elem;
    elem = elem->right;
    while(elem->left != nullptr){
        previous = elem;
        elem = elem->left;
    }
    previous->left = elem->right;
    temp->val = elem->val;
    delete elem;
    return;

}

void Tree::printTree(){
    if(this != nullptr){
        std::cout<<"(";
        this->left->printTree();
        std::cout<<","<<this->val<<",";
        this->right->printTree();
        std::cout<<")"; }
        else { 
            std::cout<<"n"; }
    }


/// @brief 
/// @param Preorder 
/// @param Inorder 
/// @param indexOfPreorder 
/// @param inorderStart 
/// @param inorderEnd 
/// @param size 
/// @return 
Tree* Tree::reconstructPreIn(int Preorder[], int Inorder[], int inorderStart, int inorderEnd){
  static int preorderIndex = 0; // Übergabe als Parameter auch möglich
  if(inorderStart > inorderEnd) return NULL;
  Tree* root = new Tree(Preorder[preorderIndex]);// First Element in Preorder is ALWAYS the root from the whole tree
  preorderIndex++;
  int indexInInorder = at(Inorder, root->val, inorderStart, inorderEnd);
  root->left  = reconstructPreIn(Preorder, Inorder, inorderStart, indexInInorder-1);
  root->right = reconstructPreIn(Preorder, Inorder, indexInInorder+1, inorderEnd); 
  
  return root;
}

 
/// @brief 
/// @param Inorder 
/// @param Postorder 
/// @param inorderStart 
/// @param inorderEnd 
/// @param size 
/// @return returns the root of the binary search tree, recursively builds the tree 
Tree* Tree::reconstructInPost(int Inorder[], int Postorder[], int inorderStart, int inorderEnd, int size){
  static int postorderIndex = size;
  Tree* root = new Tree(Postorder[postorderIndex]);
  if(inorderStart > inorderEnd) return NULL;
  int indexInInorder = at(Inorder, root->val, inorderStart, inorderEnd);
  postorderIndex--;
  root->right = reconstructInPost(Inorder, Postorder, indexInInorder+1, inorderEnd, size);
  root->left = reconstructInPost(Inorder, Postorder, inorderStart, indexInInorder-1, size);
  return root;
}

/// @brief 
/// @param array 
/// @param elem 
/// @param start 
/// @param end 
/// @return 
int at(int array[], int elem, int start, int end){
  	for(int i = start; i <= end; i++){
      if(array[i] == elem){
        return i;
      }
    }
    return -1; // if not in array

}


/*
Preorder: Wurzel erst, dann links dann rechts
Inorder: Erst links, dann Wurzel, dann rechts
Postorder: Links->Rechts->Mitte

Bsp:      D
      B       E
    A   C

Preoder: D B A C E
Inorder: A B C D E
Postord: A C B E D



*/
