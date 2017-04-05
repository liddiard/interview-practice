#include <iostream>
using namespace std;

struct Node {
  int val;
  Node * right;
  Node * left;
  Node(int v) {
    right = nullptr;
    left = nullptr;
    val = v;
  }
};

Node * makeTree(int arr[], int start, int end) {
  if (end < start)
    return nullptr;
  int mid = start + ((end - start) / 2);
  Node * root = new Node(arr[mid]);
  root->left = makeTree(arr, start, mid-1);
  root->right = makeTree(arr, mid+1, end);
  return root;
}

void inOrder(Node * cur) {
  if (cur == nullptr)
    return;
  inOrder(cur->left);
  cout << cur->val << endl;
  inOrder(cur->right);
}

int main() {
  const int SIZE = 5;
  int arr[SIZE] = {1,2,3,4,5};
  Node * tree = makeTree(arr, 0, SIZE-1);
  inOrder(tree);
  return 0;
}
