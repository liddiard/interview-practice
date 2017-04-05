#include <iostream>
using namespace std;

int ways(int n) {
  if (n < 0)
    return 0;
  else if (n == 0)
    return 1;
  else
    return ways(n - 1) + ways(n - 2) + ways(n - 3);
}

int dwaysHelper(int n, int acc[]) {
  if (n < 0)
    return 0;
  else if (n == 0)
    return 1;
  else if (acc[n] > -1)
    return acc[n];
  else {
    acc[n] = dwaysHelper(n - 1, acc) + dwaysHelper(n - 2, acc) + 
             dwaysHelper(n - 3, acc);
    return acc[n];
  }
}

int dways(int n) {
  int acc[n];
  for (int i = 0; i < n; ++i)
    acc[i] = -1;
  return dwaysHelper(n, acc);
}

int main() {
  cout << ways(10) << endl;
  cout << dways(10) << endl;
  return 0;
}