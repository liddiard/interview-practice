#include <iostream>
#include <vector>
using namespace std;

int maxSum(vector<int> arr) {
  int maxSum = 0;
  int curSum = 0;
  for (int el : arr) {
    curSum += el;
    if (curSum > maxSum) {
      maxSum = curSum;
    }
    else if (curSum < 0) {
      curSum = 0;
    }
  }
  return maxSum;
}

int main() {
  return 0;
}