#include <iostream>
#include <bitset>
#include <vector>
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

int missingNumber(vector<int>* nums, int place = 0, int known = 0) {
  if (place >= sizeof(int))
    return known;
  bool is_even = !(nums.size() % 2);
  int expected = is_even ? nums.size()/2 : nums.size()/2 + 1;
  int count 0;
  for (auto it = nums.begin(); it != nums.end(); ++it) {
    if (getBit(*it, place) == 1)
      ++count;
  }
  if (count < expected) // missing # has a 1 here
  // TODO
}

int main() {
  
}