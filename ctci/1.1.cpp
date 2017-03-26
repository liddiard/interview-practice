#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool uniqueChars(string str) {
  unordered_map <char, bool> chars;
  for (int i = 0; i < str.size(); i++) {
    if (chars[str[i]]) return false;
    else chars[str[i]] = true;
  }
  return true;
}

int main() {
  cout << uniqueChars("abcdefg");
  cout << uniqueChars("bob");
  cout << uniqueChars("");
  cout << uniqueChars("xay q ");
  return 0;
}
