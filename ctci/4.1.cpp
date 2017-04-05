#include <string>
#include <iostream>

struct Node {
  std::string data;
  Node * left;
  Node * right;

  Node() {
    left = nullptr;
    right = nullptr;
  }
};

bool isBalanced(Node * root) {
  if (root->left == nullptr && root->right == nullptr)
    return true;
  if (root->left == nullptr)
    return (root->right->right == nullptr && 
            root->right->left == nullptr);
  if (root->right == nullptr)
    return (root->left->left == nullptr &&
            root->left->right == nullptr);
  else
    return (isBalanced(root->left) &&
            isBalanced(root->right));
}

int main() {
  Node n1, n2, n3, n4, n5;
  n1.left = &n2;
  n1.right = &n3;
  n2.right = &n4;
  n4.right = &n5;
  std::cout << isBalanced(&n1);
  return 0;
}
