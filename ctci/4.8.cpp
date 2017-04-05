#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* left;
  Node* right;
  Node(int v) {
    val = v;
    left = nullptr;
    right = nullptr;
  }
};

bool identical(Node* a, Node* b) {
  if (a == nullptr && b == nullptr)
    return true;
  if (a == nullptr || b == nullptr || a->val != b->val)
    return false;
  return identical(a->left, b->left) && identical (a->right, b->right);
}

bool subtree(Node* sup, Node* sub) {
  if (sup == nullptr)
    return false;
  if (identical(sup, sub))
    return true;
  else 
    return subtree(sup->left, sub) || subtree(sup->right, sub);
}

int main() {
  Node* n1 = new Node(1);
  Node* n2 = new Node(2);
  Node* n3 = new Node(3);
  Node* n4 = new Node(4);
  Node* n5 = new Node(5);
  Node* a3 = new Node(3);
  Node* a4 = new Node(4);
  Node* a5 = new Node(5);
  n1->left = n2;
  n1->right = n3;
  n3->left = n4;
  n3->right = n5;
  a3->left = a4;
  a3->right = a5;
  cout << subtree(n1, a3) << endl;
}
