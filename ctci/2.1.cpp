#include <iostream>
#include <list>
#include <unordered_set>
using namespace std;

void removeDuplicates(list<int>& l) {
  unordered_set<int> elements;
  for (auto it = l.begin(); it != l.end();) {
    if (elements.find(*it) != elements.end())
      l.erase(it);
    else
      elements.insert(*it);
      ++it;
  }
}

// NOTE: this function with the given test cases currently fails with
// error "pointer being freed was not allocated"
void removeDuplicates2(list<int>& l) {
  auto runner = l.begin();
  for (auto it = l.begin(); it != l.end(); ++it) {
    runner = it;
    ++runner;
    while (runner != l.end()) {
      if (*runner == *it) {
        l.erase(runner);
      }
      else
        ++runner;
    }
  }
}

void printList(list<int> l) {
  for (auto it = l.begin(); it != l.end(); ++it) {
    cout << *it << ' ';
  }
  cout << endl;
}

int main() {
  list<int> list1 = { }; 
  list<int> list2 = { 1, 2, 3, 4 }; 
  list<int> list3 = { 1, 2, 3, 1 }; 
  list<int> list4 = { 1, 1, 1 }; 

  removeDuplicates2(list1);
  removeDuplicates2(list2);
  removeDuplicates2(list3);
  removeDuplicates2(list4);

  printList(list1);
  printList(list2);
  printList(list3);
  printList(list4);
}
