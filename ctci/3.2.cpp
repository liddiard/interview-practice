#include <vector>
#include <iostream>
using namespace std;

template <typename T>
struct MinMarker {
  T value;
  int count;

  MinMarker(T value) {
    this->value = value;
    this->count = 0;
  }
};

template <typename T>
class MinStack {
  vector<T> vec;
  vector< MinMarker<T> > min_markers;

  public:

  bool push(T value) {
    // add value to stack
    vec.push_back(value);
    // check if at least one min marker exists
    if (min_markers.size()) {
      // value pushed is less than current min marker
      // push a new min marker
      if (value < min_markers.back().value) {
        min_markers.push_back(MinMarker<T>(value));
      }
      // value pushed is greater than current min marker
      // increment count of current min marker
      else {
        min_markers.back().count++;
      }
    }
    // no min markers on the stack yet, push one
    else {
      min_markers.push_back(MinMarker<T>(value));
    }
    return true;
  }

  T pop() {
    if (min_markers.back().count) {
      --min_markers.back().count;
    }
    else {
      min_markers.pop_back();
    }
    T top = vec.back();
    vec.pop_back();
    return top;
  }

  T min() {
    return min_markers.back().value;
  }
};

int main() {
  MinStack<int> stack1;
  stack1.push(1);
  cout << stack1.min() << endl;
  stack1.push(2);
  cout << stack1.min() << endl;
  stack1.push(3);
  cout << stack1.min() << endl;
  cout << stack1.pop() << endl;
  cout << stack1.min() << endl;
  cout << stack1.pop() << endl;
  cout << stack1.min() << endl;
  cout << stack1.pop() << endl;
  return 0;
}
