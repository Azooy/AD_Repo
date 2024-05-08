#include <iostream>
#include "src/lib/BinarySearchTree.h"
#include "random" 


using namespace std;



int main() {
    //Driver Code
    Tree t1(100);
    Tree* t2 = new Tree(75);
    Tree* t3 = new Tree(60);
    Tree* t4 = new Tree(120);
    Tree* t5 = new Tree(140);

    t1.addTreeNode(t2);
    t1.addTreeNode(t3);
    t1.addTreeNode(t4);
    t1.addTreeNode(t5);

    t1.printTree();

    t1.deleteTreeNode(t3);
    std::cout<<"\n";

    t1.printTree();
    
    

}