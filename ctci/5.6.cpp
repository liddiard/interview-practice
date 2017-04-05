#include <iostream>
#include <bitset>
using namespace std;

int swapEveryOther(int n) {
  int odd_mask = 0xAAAAAAAA;
  int even_mask = (unsigned) odd_mask >> 1;

  int even_bits = even_mask & n;
  int odd_bits = odd_mask & n;

  return (even_bits << 1) | (odd_bits >> 1);
}

int main() {
  int n = 93;
  cout << bitset<32>(n) << endl;
  cout << bitset<32>(swapEveryOther(n)) << endl;
  return 0;
}