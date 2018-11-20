#include <iostream>
#include <memory>

struct BinaryTree {
  BinaryTree(int val): value(val) {
    left = 0;
    right = 0;   
  }

  BinaryTree *left;
  BinaryTree *right;
  int value;

  void print() {
    std::cout << value << std::endl;  
    if(left) left->print();
    if(right) right->print();
  }
  bool isBST() {
    if(!left && !right) return true; 
    bool status = true;
    if(left && value <= left->value) status &= false;
    if(right && value >= right->value) status &= false;
    if(left) status &= left->isBST();
    if(right) status &= right->isBST();

    return status;
  }
};

int main(int argc, char** argv) {
  BinaryTree bt{5};
  bt.left = new BinaryTree{3};
  bt.right  = new BinaryTree{8};
  bt.right->right = new BinaryTree{13};
  bt.print();
  std::cout << "This tree's BST status: " << bt.isBST() << std::endl;
}
