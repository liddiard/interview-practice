#include <bitset>
#include <iostream>
using namespace std;

int embed(int n, int m, int i, int j) {
  int left = (unsigned int)~0 >> (32 - j);
  int right = ~0 << i;
  int mask = ~(left & right);
  int n_cleared = n & mask;
  //cout << bitset<32>(n_cleared) << endl;
  int m_shifted = m << i;
  return n_cleared | m_shifted;
}

int main() {
  int n = 0b10000000000;
  int m = 0b10011;
  int res = embed(n, m, 2, 6);
  bitset<32> x(res);
  cout << x << endl;
  return 0;
}
