#include <iostream>
#include <cmath>

class Point {
public:
    double x, y;
    static int counter;

    Point(double x, double y) : x(x), y(y) {
        counter++;
    }

    inline double distance(const Point& other) const {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }
};

int Point::counter = 0;

int main() {
    Point p1(1.0, 2.0);
    Point p2(4.0, 6.0);
    std::cout << "Distanza tra i punti: " << p1.distance(p2) << std::endl;
    std::cout << "Numero di istanze di Point: " << Point::counter << std::endl;

    return 0;
}