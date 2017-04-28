#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct {
    bool operator()(string a, string b) {
        string acopy = a;
        string bcopy = b;
        sort(acopy.begin(), acopy.end());
        sort(bcopy.begin(), bcopy.end());
        return acopy > bcopy;
    }
} AnagramComparator;

int main() {
    vector<string> anagrams = {
        "abcd",
        "abcx",
        "dcba",
        "xbca",
        "xaxa",
        "dabc"
    };
    sort(anagrams.begin(), anagrams.end(), AnagramComparator);
    for (string anagram : anagrams) {
        cout << anagram << endl;
    }
    return 0;
}