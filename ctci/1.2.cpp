#include <iostream>
#include <algorithm>
using namespace std;

// http://forums.devshed.com/programming-42/swapping-characters-char-string-513717.html
char * reverseString(char * str) {
  char * start = str;
  char * end = str;
  while(*++end); // find end of string
  end--;
  while (start < end) {
    char tmp = *start;
    *start = *end;
    *end = tmp;
    start++;
    end--;
  }
  return str;
}

int main() {
  char mystr[] = "hello world";
  cout << reverseString(mystr) << endl;
  return 0;
}
