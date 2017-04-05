#include <iostream>
#include <bitset>
using namespace std;

int getBit(int num, int i) {
  // undefined behavior to shift more than integer width
  if (i >= 32) return -1;
  int shifted = (unsigned)num >> i;
  int mask = ~((unsigned)~0 << 1);
  return mask & shifted;
}

int setBit(int num, int i, int val) {
  int left = (unsigned)~0 << i;
  int right = (unsigned)~0 >> ((32 - i) - 1);
  int mask = ~(left & right);
  int num_unset = num & mask;
  return (val << i) | num_unset;
}

int getNext(int num) {
  int trailing_zeroes = 0;
  int trailing_ones = 0;
  while (getBit(num, trailing_zeroes) == 0)
    ++trailing_zeroes;
  while (getBit(num, trailing_zeroes + trailing_ones) == 1)
    ++trailing_ones;
  int cur = trailing_zeroes + trailing_ones;
  int one_added = setBit(num, cur, 1);
  int zeroes_shifted = (one_added >> cur) << cur;
  int ones_mask = (unsigned)~0 >> (32 - (trailing_ones - 1));
  //cout << bitset<32>(ones_mask) << endl;
  return zeroes_shifted | ones_mask;
}

// TODO
int getPrevious(int num) {}

int main() {
  int num = 13948;
  cout << bitset<32>(num) << endl;
  cout << bitset<32>(getNext(num)) << endl;
  return 0;
}