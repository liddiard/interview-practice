#include <stack>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void stackSort(stack<T> &s1) {
  stack<T> s2;
  T tmp;
  int num_popped;
  const int size = s1.size();
  // for each element in s1
  for (int i = 0; i < size; i++) {
    num_popped = 0;
    tmp = s1.top();
    s1.pop();
    while (s2.size()) {
      if (s2.top() < tmp) {
        break;
      }
      else {
        s1.push(s2.top());
        s2.pop();
        ++num_popped;
      }
    }
    s2.push(tmp);
    // put items popped off s2 back onto it
    for (int j = 0; j < num_popped; j++) {
      s2.push(s1.top());
      s1.pop();
    }
  }
  while (s2.size()) {
    s1.push(s2.top());
    s2.pop();
  }
}

template <typename T>
stack<T> stack_sort(stack<T> s1) {
  stack<T> s2;
  T tmp;
  while (s1.size()) {
    tmp = s1.top();
    s1.pop();
    while (s2.size() && tmp < s2.top()) {
      s1.push(s2.top());
      s2.pop();
    }
    s2.push(tmp);
  }
  return s2;
}

int main() {
  stack<int> mystack;
  mystack.push(8);
  mystack.push(5);
  mystack.push(2);
  mystack.push(3);
  mystack.push(4);
  stack<int> sorted = stack_sort(mystack);
  while(sorted.size()) {
    cout << sorted.top() << endl;
    sorted.pop();
  }
  return 0;
}
