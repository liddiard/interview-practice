#include <iostream>
#include <queue>
#include <list>
using namespace std;

struct Node {
  list<Node *> neighbors;
  bool visited;
  Node() {
    visited = false;
  }
};

bool connected(Node * start, Node * end) {
  queue<Node *> toVisit;
  Node * cur = start;
  do {
    if (cur == end)
      return true;
    else
      cur->visited = true;
    for (auto it = cur->neighbors.begin(); 
         it != cur->neighbors.end(); it++) {
      if (!(*it)->visited)
        toVisit.push(*it);
    }
    cur = toVisit.back();
    toVisit.pop();
  } while(!toVisit.empty());
  return false;
}

int main() {
  Node n1, n2, n3, n4, n5;
  n1.neighbors.push_back(&n2);
  n1.neighbors.push_back(&n3);
  n3.neighbors.push_back(&n4);
  cout << connected(&n1, &n5) << endl;
  return 0;
}
