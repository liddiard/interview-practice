#include <cmath>
#include <iostream>
using namespace std;

class Line {
  public:
  double slope;
  double yint;
  double epsilon = .000001;

  Line(double s, double y) {
    slope = s;
    yint = y;
  }

  bool intersectsWith(Line* line) {
    return (abs(yint - line->yint) < epsilon && abs(slope - line->slope) < epsilon) ||
            abs(slope - line->slope) > epsilon;
  }
};

int main() {
  Line* l1 = new Line(0.5, 10);
  Line* l2 = new Line(0.5, 5);
  cout << l1->intersectsWith(l2) << endl;
  return 0;
}
