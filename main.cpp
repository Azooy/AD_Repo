#include <iostream>
#include "src/lib/BinarySearchTree.h"
#include "src/lib/AVLTree.h"
#include "random" 


using namespace std;



int main() {
  //Driver Code
  
 

  int values[] = {6,9,12,13,3,8,10,11,16};//,15,14,4,2,1};
  AVL* root = new AVL(5);
  root->Insert(root,6);
  root->Insert(root,9);
  root->Insert(root,12);
  root->Insert(root,13);
  root->Insert(root,3);
  root->Insert(root,8);
  root->Insert(root,10);
  root->Insert(root,11);
  //root->Insert(root,16);*/

  root->printAVL();
  std::cout << "\n \n";
  system("pause");
  

  




  

  return 0;
    
    

}