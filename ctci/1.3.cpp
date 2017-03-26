#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

bool isPermutationOf(string str1, string str2) {
  unordered_map<char, int> freq;
  for (int i = 0; i < str1.size(); i++) {
    if (freq.count(str1[i]))
      freq[str1[i]]++;
    else
      freq[str1[i]] = 1;
  }
  for (int i = 0 ; i < str2.size(); i++) {
    if (!freq.count(str2[i]) || freq[str2[i]] == 0) 
      return false;
    else
      freq[str2[i]]--; 
  }
  return true;
}

int main() {
  cout << isPermutationOf("hello", "help");
  return 0;
}
