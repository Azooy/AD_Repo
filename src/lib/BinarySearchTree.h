#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H 

class Tree{
    int val;
    Tree* left;
    Tree* right;
public:
    Tree();
    Tree(int);
    Tree(int, Tree*);
    Tree(int, Tree*, Tree*);

    void deleteTreeNode(Tree*);
    void addTreeNode(Tree*);
    Tree* findTreeNode(Tree*);
    void deleteTreeNodeRek(Tree*);
    void printTree();
};

#endif