#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

class node;
class tree;

class tree{
    node* root;

public:
    tree();
    tree(node*);

void insertNode(node*);
};

class node{
    int value;
    node* left;
    node* right;
public:
    node();
    node(int);
    node(int, node*);
    node(int, node*, node*);


friend class tree;
};

node* createNode(int);


#endif
