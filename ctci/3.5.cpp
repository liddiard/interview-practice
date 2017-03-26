#include <stack>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class MyQueue {
  stack<T> forward;
  stack<T> reversed;

  void swap_stacks() {
    stack<T> origin, destination;
    if (forward.size()) {
      origin = forward;
      destination = reversed;
    }
    else {
      origin = reversed;
      destination = forward;
    }
    T val = origin.top();
    while (origin.size()) {
      destination.push(val);
      val = origin.top();
      origin.pop();
    }
  }

public:
  int size() {
    return forward.size() ? forward.size() : reversed.size();
  }

  void push(T val) {
    if (reversed.size()) {
      swap_stacks();
    }
    forward.push(val);
  }

  T pop() {
    if (!reversed.size()) {
      swap_stacks();
    }
    T val = forward.top();
    forward.pop();
    return val;
  }
};

int main() {
  MyQueue<string> q;
  q.push("Lorem");
  q.push("ispum");
  q.push("dolor");
  cout << q.pop() << endl;
  q.push("sit");
  q.push("amet.");
  while(q.size())
    cout << q.pop() << endl;
  return 0;
}
