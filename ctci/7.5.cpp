#include <iostream>
using namespace std;

class Line {
  public:
  double slope;
  double yint;
  Line(double s, double y) {
    slope = s;
    yint = y;
  }
};

// TODO: unlike assumptions in solution, doesn't give line segment start and
// end points (requires a lot of math)

class Square {
  public:
  double x;
  double y;
  double size;

  Line bisectWith(Square* other) {
    double slope = (y - other->y) / (x - other->x);
    double yint = y - (slope * x);
    return Line(slope, yint);
  }
};

int main() {
  return 0;
}