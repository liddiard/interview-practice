#include <iostream>
#include <string>
using namespace std;

struct Result {
  int hits;
  int pseudoHits;
  Result(int h, int p) {
    hits = h;
    pseudoHits = p;
  }
};

Result guess(string guess, string solution) {
  int hits, pseudoHits = 0;
  for (int i = 0; i < guess.size(); ++i) {
    if (guess[i] == solution[i]) {
      ++hits;
    }
    else if (solution.find(guess[i])) {
      ++pseudoHits;
    }
  }
  return Result(hits, pseudoHits);
}

int main() {
  Result r = guess("GGRR", "RGBY");
  cout << r.hits << " " << r.pseudoHits << endl;
  return 0;
}