#include <iostream>

void swap(int &a, int &b) {
  a = a - b; // difference between a and b
  b = a + b; // b's current value plus difference
  a = b - a;
}