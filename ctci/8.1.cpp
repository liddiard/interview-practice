#include <string>
#include <iostream>
using namespace std;

class Card {
  public:
  string suit;
  string rank;
  Card() {}
  Card(string suit, string rank) {
    this->suit = suit;
    this->rank = rank;
  }
};

class Deck {
  private:
  static const unsigned numCards = 52;
  Card cards[numCards];
  public:
  static const string suits[];
  static const string ranks[];
  Deck();
  void printCards();
};

const string Deck::suits[] = { "hearts", "clubs", "spades", "diamonds" };
const string Deck::ranks[] = {
  "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", 
  "jack", "queen", "king", "ace"
};

Deck::Deck() {
  int cur = 0;
  for (string suit : suits) {
    for (string rank : ranks) {
      cards[cur++] = Card(suit, rank);
    }
  }
};

void Deck::printCards() {
  for (int i = 0; i < numCards; ++i) {
    cout << cards[i].rank << " of " << cards[i].suit << endl;
  }
}

int main() {
  Deck mydeck = Deck();
  mydeck.printCards();
  return 0;
}