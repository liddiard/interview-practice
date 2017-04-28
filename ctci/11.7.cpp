#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
H 10 11 12 13 14 15
W 10 12 50 13 14 15 

H 10 11 13 14 15 12
W 10 12 13 14 15 50
*/

struct Person {
  int height;
  int weight;
  Person(int h, int w) {
    height = h;
    weight = w;
  }
};

enum measure {
  height,
  weight
};

bool sortByHeight(Person& a, Person& b) {
  return a.height < b.height;
}

bool sortByWeight(Person& a, Person& b) {
  return a.weight < b.weight;
}

int longestSubsequence(vector<Person>* people, measure m) {
  int longest = 0;
  int cur_length = 0;
  int prev_value = 0;

  for (auto it = people->begin(); it != people->end(); ++it) {
    cur_length = 0;
    prev_value = 0;
    for (auto it2 = it; it != people->end(); ++it2) {
      switch (m) {
        case height:
          if ((*it2).height > prev_value) {
            prev_value = (*it2).height;
            ++cur_length;
            break;
          }
          goto next;
        case weight:
          if ((*it2).weight > prev_value) {
            prev_value = (*it2).weight;
            ++cur_length;
            break;
          }
          goto next;
        default:
          throw invalid_argument("bad measure argument");
      }
    }
    next:
    if (cur_length > longest) {
      longest = cur_length;
    }
  }
  return longest;
}

int tallestTower(vector<Person> people) {
  vector<Person> sortedHeight = people;
  vector<Person> sortedWeight = people;
  sort(sortedHeight.begin(), sortedHeight.end(), sortByHeight);
  sort(sortedWeight.begin(), sortedWeight.end(), sortByWeight);
  int longest_height = longestSubsequence(&sortedHeight, weight);
  int longest_weight = longestSubsequence(&sortedWeight, height);
  return max(longest_height, longest_weight);
}

int main() {
  vector<Person> people = {
    Person(10, 10),
    Person(11, 12),
    Person(12, 50),
    Person(13, 13),
    Person(14, 14),
    Person(15, 15)
  };
  cout << tallestTower(people) << endl;
  return 0;
}