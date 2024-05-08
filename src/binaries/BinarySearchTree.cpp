#include "../lib/BinarySearchTree.h"
#include "iostream"

Tree::Tree():val(0), left(nullptr), right(nullptr){};


Tree::Tree(int val_): val(val_), left(nullptr), right(nullptr){};
Tree::Tree(int val_, Tree* left_):val(val_), left(left_), right(nullptr){};
Tree::Tree(int val_, Tree* left_, Tree* right_): val(val_), left(left_), right(right_){};

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


void Tree::deleteTreeNode(Tree* ToDelete){
    Tree* currentNode = this;
    Tree* elem;
    Tree* temp;
    elem = currentNode->findTreeNode(ToDelete);
    if(elem->left == nullptr){ // No successor
        if(elem->right == nullptr){
            elem = nullptr;
            return;
        }
    }

    if(elem->left != nullptr){
        if(elem->right == nullptr){
            temp = elem;
            elem = elem->left;
            delete temp;
            return;
        }
    }

    if(elem->right != nullptr){
        if(elem->left == nullptr){
            temp = elem;
            elem = elem->right;
            delete temp;
            return;
        }
    }
    temp = elem;
    temp = temp->right;
    Tree* previous;
    previous = temp;
    while(temp->left != nullptr){
        previous = temp;
        temp = temp->left;
    }
    previous->left = temp->right;
    delete temp;
    
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






/*
         13
      7     18
    5  8   14  19
*/