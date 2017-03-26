#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

class Point
{
    public:
    Point(int x, int y);
    double distance_from_origin();
    void print();

    private:
    int x;
    int y;
};

bool compare_distance_from_origin(Point a, Point b)
{
    return a.distance_from_origin() > b.distance_from_origin();
}

vector<Point>::iterator n_closest_points(vector<Point>& points, int n)
{
    sort(points.begin(), points.end(), compare_distance_from_origin);
    vector<Point>::iterator it = points.begin();
    it += (points.size() - n);
    return it;
}

int main()
{
    vector<Point> points;
    points.push_back(Point(2,2));
    points.push_back(Point(1,1));
    points.push_back(Point(5, 5));
    points.push_back(Point(1, 2));
    points.push_back(Point(5,2));

    vector<Point>::iterator it = n_closest_points(points, 3);
    for (; it != points.end(); ++it)
    {
        it->print();
    }
    return 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

double Point::distance_from_origin()
{
    return sqrt( pow((double)(x), 2.0) + pow((double)(y), 2.0) );
}

void Point::print()
{
    cout << "(" << x << ", " << y << ")\n";
}
