#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void printLast10Lines(string filename) {
  const int k = 10;
  string buffer[k];
  ifstream file (filename);
  int size = 0;
  while (file.good()) {
    getline(file, buffer[size % k]);
    ++size;
  }
  int start = size > k ? size % k : 0;
  int count = size > k ? k : size;

  for (int i = 0; i < count; ++i) {
    cout << buffer[(start + i) % k] << endl;
  }
}

int main() {
  printLast10Lines("11.8.cpp");
  return 0;
}