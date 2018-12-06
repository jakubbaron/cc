#include <iostream>
#include <queue>

struct BinaryTree {
  BinaryTree(int val): value(val) {
    left = 0;
    right = 0;   
  }

  BinaryTree *left;
  BinaryTree *right;
  int value;
};

using level_tree_pair = std::pair<int, BinaryTree*>;
void print_levels(BinaryTree* root) {
  static std::queue<level_tree_pair> q;
  int current_level = 1;
  if(root == nullptr) return;

  q.emplace(std::make_pair(current_level, root));
  while(!q.empty()) {
    auto curr_el = q.front();
    q.pop();
    const auto& curr_node = curr_el.second;
    if(curr_el.first != current_level) {
      std::cout << "\n";
      current_level = curr_el.first;
    }
    std::cout << curr_node->value << " ";
    if(curr_node->left != nullptr) {
      q.emplace(std::make_pair(current_level + 1, curr_node->left));
    }
    if(curr_node->right != nullptr) {
      q.emplace(std::make_pair(current_level + 1, curr_node->right));
    }
  }
  std::cout << "\n";

}


int main(int argc, char** argv) {
  BinaryTree *bt = new BinaryTree{5};
  bt->left = new BinaryTree{3};
  bt->right  = new BinaryTree{8};
  bt->right->right = new BinaryTree{13};
  bt->right->left= new BinaryTree{53};
  bt->left->left= new BinaryTree{10};
  bt->left->right= new BinaryTree{20};

  print_levels(bt);

  return 0;
}
