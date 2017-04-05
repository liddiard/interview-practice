#include <iostream>
using namespace std;

struct Node {
  Node* left;
  Node* right;
  Node() {
    left = nullptr;
    right = nullptr;
  }
};

bool childOf(Node* node, Node* root) {
  if (root == nullptr)
    return false;
  if (root == node)
    return true;
  return childOf(node, root->left) || childOf(node, root->right);
}

Node* ancestor(Node* a, Node* b, Node* root) {
  if (childOf(a, root->left) && childOf(b, root->left))
    return ancestor(a, b, root->left);
  else if (childOf(a, root->right) && childOf(b, root->right))
    return ancestor(a, b, root->right);
  else
    return root;
}

int main() {
  Node n1,n2,n3,n4,n5;
  cout << &n1 << endl << &n2 << endl << &n3 << endl << &n4 << endl << &n5 << endl << endl;
  n1.left = &n2;
  n1.right = &n3;
  n2.left = &n4;
  n2.right = &n5;
  cout << ancestor(&n4, &n5, &n1) << endl;
  return 0;
}
