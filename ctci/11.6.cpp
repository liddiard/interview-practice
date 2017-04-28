#include <iostream>
#include <cmath>

struct Point {
  int x;
  int y;
  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }
  bool operator >(Point* other) {
    return (x + y) > (other->x + other->y);
  }
}

Point search(int arr[][], int width, int height, int target, 
             int x_low, int x_high, int y_low, int y_high) {
  int x_mid = (x_low + x_high) / 2;
  int y_mid = (y_low + y_high) / 2;
  if (x_low > x_high || y_low > y_high) {
    return Point(-1);
  }
  if (arr[y_mid][x_mid] == target) {
    return Point(x_mid, y_mid);
  }
  if (target > arr[y_mid][x_mid]) {
    // branch one forward and one down  
    return Math.max(
      search(arr, width, height, target, x_mid+1, x_high, y_mid, y_high),
      search(arr, width, height, target, x_mid, x_high, y_mid+1, y_high)
    );
  }
  else {
    return Math.max(
      search(arr, width, height, target, x_low, x_mid-1, y_mid, y_high),
      search(arr, width, height, target, x_low, x_mid, y_mid-1, y_high)
    )
  }
}

int main() {
  return 0;
}