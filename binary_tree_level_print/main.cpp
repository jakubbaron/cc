#include <iostream>
#include <queue>
#include <memory>

struct BinaryTree {
  BinaryTree(int val): value(val) {
    left = nullptr;
    right = nullptr;   
  }

  std::shared_ptr<BinaryTree> left;
  std::shared_ptr<BinaryTree> right;
  int value;
};

using level_tree_pair = std::pair<int, std::shared_ptr<BinaryTree> >;
void print_levels(std::shared_ptr<BinaryTree> root) {
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
  auto bt = std::make_shared<BinaryTree>(5);
  bt->left = std::make_shared<BinaryTree>(3);
  bt->right  = std::make_shared<BinaryTree>(8);
  bt->right->right = std::make_shared<BinaryTree>(13);
  bt->right->left= std::make_shared<BinaryTree>(53);
  bt->left->left= std::make_shared<BinaryTree>(10);
  bt->left->right= std::make_shared<BinaryTree>(20);

  print_levels(bt);

  return 0;
}
