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
    ~Tree();

    Tree* reconstructInPost(int[], int[], int, int, int);
    Tree* findPre(Tree*);
    void deleteTreeNode(Tree*);
    void addTreeNode(Tree*);
    Tree* findTreeNode(Tree*);
    void deleteTreeNodeRek(Tree*);
    void printTree();
    void swapNodes(Tree*);
    Tree* reconstructPreIn(int[], int[], int, int);
    
};

int at(int[], int, int, int);

#endif