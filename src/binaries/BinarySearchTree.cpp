#include "../lib/BinarySearchTree.h"

tree::tree():root(nullptr){};
tree::tree(node* root_):root(root_){};
void tree::insertNode(node* newNode){
    node* root = this->root;
    node* left_temp = root->left;
    node* right_temp = root->right;



}

node::node():value(0), left(nullptr), right(nullptr){};
node::node(int val_): value(val_), left(nullptr), right(nullptr){};
node::node(int val_, node* left_): value(val_), left(left_), right(nullptr){};
node::node(int val_, node* left_, node* right_): value(val_), left(left_), right(right_){};

node* createNode(int val_){
    node* newN = new node(val_);
    return newN;
}