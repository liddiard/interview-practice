#include <cmath>
#include <iostream>
#include <stdexcept>

int negate(int n) {
  if (n == 0)
    return 0;
  int step = n > 0 ? -1 : 1;
  int result = 0;
  for (int i = 0; i < abs(n); ++i) {
    result += step;
  }
  return result;
}

int subtract(int a, int b) {
  return a + negate(b);
}

int multiply(int a, int b) {
  if (a == 0 || b == 0)
    return 0;
  bool positive = (a > 0 && b > 0) || (a < 0 && b < 0);
  int acc = abs(a);
  for (int i = 1; i < abs(b); ++i) {
    acc += abs(a);
  }
  return positive ? acc : negate(acc);
}

int divide(int a, int b) {
  if (b == 0) {
    throw std::out_of_range("cannot divide by zero");
  }
  bool positive = (a > 0 && b > 0) || (a < 0 && b < 0);
  int iter = 0;
  int acc = abs(b);
  while (acc <= abs(a)) {
    acc += abs(b);
    ++iter;
  }
  return positive ? iter : negate(iter);
}

int main() {
  std::cout << multiply(-5, 2) << std::endl;
  return 0;
}