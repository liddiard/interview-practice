#include <iostream>
#include <bitset>
using namespace std;

int numDiffBits(int n1, int n2) {
  int diff = n1 ^ n2;
  int mask = 1;
  int numOnes = 0;
  for (int i = 0; i < 32; i++) {
    if (((diff >> i) & mask) == 1)
      ++numOnes;
  }
  return numOnes;
}

int main() {
  int n1 = 95;
  int n2 = 86;
  cout << bitset<32>(n1) << endl;
  cout << bitset<32>(n2) << endl;
  cout << numDiffBits(n1, n2) << endl;
  return 0;
}