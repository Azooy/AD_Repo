#include "../lib/AVLTree.h"
AVL::AVL() : val(NULL), height(0), left(nullptr), right(nullptr){};
AVL::AVL(int val_) : val(val_), height(0), left(nullptr), right(nullptr){};
AVL::~AVL()
{
  this->val = NULL;
  this->left = nullptr;
  this->right = nullptr;
}

int AVL::getHeight()
{
  if (this == nullptr)
    return -1;
  return this->height;
}

int AVL::maxHeight(int a, int b)
{
  return (a < b) ? b : a;
}

void AVL::updateHeight(AVL *root)
{
  int leftHeight = (root->left == nullptr) ? -1 : root->left->height;
  int rightHeight = (root->right == nullptr) ? -1 : root->right->height;
  root->height = AVL::maxHeight(leftHeight, rightHeight) + 1;
}

void AVL::CreateAVL(AVL *&root_ref, int value)
{
  AVL *newAVL = new AVL(value);
  if (newAVL->val < root_ref->val)
  {
    if (root_ref->left == nullptr)
    {
      root_ref->left = newAVL;
      updateHeight(root_ref);
      return;
    }
    else
    {
      // root_ref=root_ref->left;
      CreateAVL(root_ref->left, value);
      checkForRightRotation(root_ref);
      updateHeight(root_ref);
    }
  }
  if (newAVL->val > root_ref->val)
  {
    if (root_ref->right == nullptr)
    {
      root_ref->right = newAVL;
      updateHeight(root_ref);
      return;
    }
    else
    {
      // root_ref=root_ref->right;
      CreateAVL(root_ref->right, value);
      checkForLeftRotation(root_ref);
      updateHeight(root_ref);
    }
  }
  updateHeight(root_ref);
}

void AVL::printAVL()
{
  if (this != nullptr)
  {
    std::cout << "(";
    this->left->printAVL();
    std::cout << "," << this->val << ",";
    this->right->printAVL();
    std::cout << ")";
  }
  else
  {
    std::cout << "n";
  }
}

void AVL::checkForLeftRotation(AVL *&root)
{
  if (root != nullptr)
  {
    if (root->right != nullptr)
    {
      int rightHeight = root->right->getHeight();
      int leftHeight = root->left->getHeight();
      if (rightHeight - leftHeight == 2)
      {
        if (root->right->left->getHeight() > root->right->right->getHeight())
        { // Is the right inner subtree too high?
          leftRightRotation(root);
        }
        else
        {
          leftRotation(root);
        }
      }
      else
      {
        updateHeight(root);
      }
    }
    else
    {
      updateHeight(root);
    }
  }
}

void AVL::checkForRightRotation(AVL *&root)
{
  if (root != nullptr)
  {
    if (root->left != nullptr)
    {
      int rightHeight = root->right->getHeight();
      int leftHeight = root->left->getHeight();
      if (leftHeight - rightHeight == 2)
      {
        if (root->left->right->getHeight() > root->left->left->getHeight())
        {
          righLeftRotation(root);
        }
        else
        {
          rightRotation(root);
        }
      }
      else
      {
        updateHeight(root);
      }
    }
    else
    {
      updateHeight(root);
    }
  }
}

void AVL::rightRotation(AVL *&root)
{ // 18 27 23 28
  /*
        A           B
      B     ->    C   A
    C   D            D
  */
  AVL *B = root->right;
  root->left = B->left;
  B->right = root;
  root = B;

  updateHeight(root->right);
  updateHeight(root);
}

void AVL::leftRightRotation(AVL *&root)
{ // Rechts-Links-Rotation => in the right subtree the left subtree (inner) is too high ==>> Right rotation
  rightRotation(root->right);
  leftRotation(root);
}

void AVL::righLeftRotation(AVL *&root)
{ // Links-Rechts-Rotation => in the left subtree the right subtree (inner) is too high ==>> Left Rotation
  leftRotation(root->left);
  rightRotation(root);
}

void AVL::leftRotation(AVL *&root)
{
  /*
      A                  B
        B       ->    A     D
      C   D             C

  */
  AVL *b = root->right;
  root->right = b->left;
  b->left = root;
  root = b;

  updateHeight(root->left);
  updateHeight(root);
}

int numOfAVLTrees(int h){
  if(h == 0){
    return 1;
  }
  if(h==1){
    return 2;
  }

  return 1 + numOfAVLTrees(h-1) + numOfAVLTrees(h-2);

};

void AVL::Insert(AVL* &ref, int value){
  if(value < ref->val){
    if(ref->left == nullptr){
       AVL* newNode = new AVL(value);
       ref->left = newNode;
    } else {
      Insert(ref->left, value);
      checkForRightRotation(ref);
    }
  }
  if(value > ref->val){
    if(ref->right == nullptr){
      AVL* newNode = new AVL(value);
      ref->right = newNode;
  }
  else{
    Insert(ref->right, value);
    checkForLeftRotation(ref);
    }
  }

  updateHeight(ref);



}