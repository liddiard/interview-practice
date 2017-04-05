#include <vector>
#include <list>
#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* right;
  Node* left;
  Node(int val) {
    this->val = val;
    right = nullptr;
    left = nullptr;
  }
};

vector<list<Node*>>* nodesByLevel(Node* root, vector<list<Node*>>* nodes, int curLevel)
{
  if (root == nullptr)
    return nodes;
  if (curLevel == nodes->size())
    nodes->push_back(list<Node*>());
  (*nodes)[curLevel].push_back(root);
  nodesByLevel(root->left, nodes, curLevel+1);
  nodesByLevel(root->right, nodes, curLevel+1);
  return nodes;
}

int main() {
  vector<list<Node*>>* nodes = new vector<list<Node*>>;
  Node* n1 = new Node(1);
  Node* n2 = new Node(2);
  Node* n3 = new Node(3);
  Node* n4 = new Node(4);
  Node* n5 = new Node(5);
  n1->left = n2;
  n1->right = n3;
  n2->right = n4;
  n4->left = n5;
  nodesByLevel(n1, nodes, 0);
  for (auto it = nodes->begin(); it != nodes->end(); it++) {
    cout << "level" << endl;
    for (auto it2 = (*it).begin(); it2 != (*it).end(); it2++) {
      cout << (*it2)->val << endl;
    }
  }
  return 0;
}
