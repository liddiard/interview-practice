#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Range {
  int begin, end;
  Range(int b, int e) {
    begin = b;
    end = e;
  }
};

Range rangeToSort(vector<int> ns) {
  int first = 0;
  int last = 0;
  int max = INT_MIN;
  int min = INT_MAX;
  for (int i = 0; i < ns.size()-1; ++i) {
    if (ns[i+1] < ns[i]) {
      if (!first) first = i+1;
      last = i+1;
      if (ns[i+1] > max) max = ns[i+1];
      if (ns[i+1] < min) min = ns[i+1];
    }
  }
  cout << last << endl;
  int begin = first;
  int end = last;
  for (int i = first - 1; i >= 0; --i) {
    if (ns[i] <= min) {
      begin = i + 1;
      break;
    }
  }
  for (int i = last + 1; i < ns.size(); ++i) {
    if (ns[i] >= max) {
      end = i;
      break;
    }
  }
  return Range(begin, end);
}

int main() {
  vector<int> myVec = { 1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19 };
  Range ans = rangeToSort(myVec);
  cout << ans.begin << " " << ans.end << endl;
  return 0;
}