#include <iostream>
using namespace std;

struct Node {
  int val;
  int left_size;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(int v, int lsc) {
    val = v;
    left_subtree_count = lsc;
  }
};

class BinarySearchTree {
  private:
  Node* root = nullptr;
  Node* search(int x) {
    return search(x, root);
  }
  Node* search(int x, Node* root) {
    if (root == nullptr) {
      return nullptr;
    }
    if (root->val == x) {
      return root;
    }
    if (x < root->val) {
      return search(x, root->left);
    }
    else { // x is larger than root value
      return search(x, root->right);
    }
  }
  public:
  bool track(int x, Node* root) {
    if (root == nullptr) {
      root = new Node(x);
    }
    if (root->val == x) {
      return false; // not inserted
    }
    if (x < root->val) {
      if (root->left == nullptr) {
        return true;
        root->left = new Node(x);
      }
      else {
        return insert(x, root->left);
      }
    }
    else { // x is greater than root value
      if (root->right == nullptr) {
        root->right = new Node(x);
        return true;
      }
      else {
        return insert(x, root->right);
      }
    }
  }
  int getRank(int x, Node* root) {
    if (x == root->val) {
      return root->left_size;
    }
    if (x < root->val) {
      return getRank(x, root->left);
    }
    else {
      return root->left_size + 1 + getRank(x, root->right);
    }
  }
};