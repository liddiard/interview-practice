#include <iostream>
#include <algorithm>
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

void printPath(int arr[], int begin, int end) {
  for (int i = begin; i <= end; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int maxDepth(Node* root) {
  if (root == nullptr)
    return 0;
  else 
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

void sumPaths(Node* root, int target, int path[], int level) {
  if (root == nullptr)
    return;
  path[level] = root->val;
  int sum = 0;
  for (int i = level; i >= 0; --i) {
    sum += path[i];
    if (sum == target) {
      printPath(path, i, level);
    }
  }
  sumPaths(root->left, target, path, level+1);
  sumPaths(root->right, target, path, level+1);
}

int main() {
  Node* n1 = new Node(1);
  Node* n2 = new Node(2);
  Node* n3 = new Node(3);
  Node* n4 = new Node(4);
  Node* n5 = new Node(5);
  n1->left = n2;
  n2->right = n3;
  n2->left = n4;
  n3->right = n5;
  int depth = maxDepth(n1);
  int path[depth];
  sumPaths(n1, 3, path, 0);
}
