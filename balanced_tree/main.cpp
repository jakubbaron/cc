#include <iostream>
#include <algorithm>

struct node {
  node(int data):data(data), left(NULL), right(NULL) {}
  int data;
  node* left;
  node* right;
};

bool isBalanced(node* root, int& height) {
  int lh{0}, rh{0};
  bool l{false}, r{false};
  if(root == NULL) {
    height = 0;
    return true;
  }

  l = isBalanced(root->left, lh);
  r = isBalanced(root->right, rh);

  height = std::max(lh, rh) + 1;

  if(std::abs(lh - rh) >= 2) {
    return false;
  }

  return l && r;
}

int main(int argc, char** argv) {
  node *root = new node(1);   
  root->left = new node(2); 
  root->right = new node(3); 
  root->left->left = new node(4); 
  root->left->right = new node(5); 
  root->right->left = new node(6); 
  root->left->left->left = new node(7);   

  int height = 0;
  if(isBalanced(root, height)) 
    std::cout<< "Tree is balanced" << std::endl; 
  else
    std::cout<< "Tree is not balanced" << std::endl;; 

  return 0;
}
