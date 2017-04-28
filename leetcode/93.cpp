#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool validRange(int i) {
  return i >= 0 && i <= 255;
}

vector<string> restoreIpAddresses(string s) {
  vector<string> options;
  int s1, s2, s3, s4;
  string opt;
  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= 3; ++j) {
      for (int k = 1; k <= 3; ++k) {
        for (int l = 1; l <= 3; ++l) {
          if (i+j+k+l != s.size())
            continue;
          s1 = stoi(s.substr(0, i));
          s2 = stoi(s.substr(i, j));
          s3 = stoi(s.substr(i+j, k));
          s4 = stoi(s.substr(i+j+k, l));
          if (validRange(s1) && validRange(s2) && 
              validRange(s3) && validRange(s4)) {
            opt = to_string(s1)+"."+to_string(s2)+"."+to_string(s3)+"."+to_string(s4);
            if (opt.size() == s.size()+3) {
              options.push_back(opt);
            }
          }
        }
      }
    }
  }
  return options;
}

int main() {
  vector<string> opts = restoreIpAddresses("25525511135");
  for (string opt : opts) {
    cout << opt << endl;
  }
  return 0;
}