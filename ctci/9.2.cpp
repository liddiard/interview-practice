#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int factorial(int n) {
  if (n == 0)
    return 1;
  return n * factorial(n - 1);
}

int paths(int x, int y) {
  int total = x + y;
  return factorial(total) / ((double)factorial(total - y) * factorial(y));
}

struct Point {
  int x;
  int y;
  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }
};

bool canMove(int x, int y) {
  return true;
}

bool findPath(int x, int y, vector<Point>* path) {
  
}

int main() {
  cout << paths(5, 5) << endl;
  return 0;
}