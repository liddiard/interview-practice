#include <iostream>
using namespace std;

struct Node {
  int val;
  Node * left;
  Node * right;
  Node(int val) {
    this->val = val;
    right = nullptr;
    left = nullptr;
  }
};

bool isBST(Node * root, int lowerBound, int upperBound) {
  if (root == nullptr)
    return true;
  cout << root->val << " " << lowerBound << " " << upperBound << endl;
  if (root->val > lowerBound && root->val <= upperBound)
    return isBST(root->left, lowerBound, root->val) && isBST(root->right, root->val, upperBound);
  else 
    return false;
}

int main() {
  Node* n1 = new Node(25);
  Node* n2 = new Node(10);
  Node* n3 = new Node(20);
  Node* n4 = new Node(30);
  Node* n5 = new Node(40);
  n3->left = n2;
  n2->right = n1;
  n3->right = n4;
  n4->right = n5;
  cout << isBST(n3, numeric_limits<int>::min(), numeric_limits<int>::max()) << endl;
}
