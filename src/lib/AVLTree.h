#ifndef AVLTREE_H
#define AVLTREE_H 
#include "stdlib.h"
#include "iostream"

/// @brief 
/// int val, int height, avl* left, avl* right
class AVL{
  int val;
  int height=-1;
  AVL* left;
  AVL* right;
public:
  AVL();
  AVL(int);
  ~AVL();
  void CreateAVL(AVL* &,int);
  void DeleteAVL(AVL*);
  void printAVL();
  void updateHeight(AVL*);
  int maxHeight(int, int);
  void checkForLeftRotation(AVL* &);
  void checkForRightRotation(AVL* &);
  void rightRotation(AVL* &);
  void leftRotation(AVL* &);
  int getHeight();
  void Insert(AVL* &, int);
  void leftRightRotation(AVL* &); // Rechts-Links-Rotation => in the right subtree the left subtree (inner) is too high ==>> Right rotation
  void righLeftRotation(AVL* &); // Links-Rechts-Rotation => in the left subtree the right subtree (inner) is too high ==>> Left Rotation
};


int numOfAVLTrees(int);




#endif