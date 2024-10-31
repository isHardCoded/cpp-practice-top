#include <iostream>
#include <cmath>

class Point {
private:
    double x;
    double y;

public:
    Point() {};

    Point(double xv, double yv) : x(xv), y(yv) {}

    double getDistanceToMain() const {
        return std::sqrt(x * x + y * y);
    }

    bool operator<(const Point& other) const {
        return getDistanceToMain() < other.getDistanceToMain();
    }

    bool operator>(const Point& other) const {
        return getDistanceToMain() > other.getDistanceToMain();
    }
};

int main()
{
    Point pt1(2.2, 4.1);
    Point pt2(6.3, 8.2);

    if (pt1 > pt2) {
        std::cout << "pt1 is farther from the main point than pt2" << std::endl;
    }

    else if (pt1 < pt2) {
        std::cout << "pt2 is farther from the main point than pt1" << std::endl;
    }

    else {
        std::cout << "pt1 = pt2";
    }
}