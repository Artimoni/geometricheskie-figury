#include "figures.h"
#include <cmath>
#include <fstream>
#include <cstdlib>

const double PI = 3.141592653589793;

static double dist(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
} //расстояние между двумя точками

Circle::Circle(Point c, double r) : center(c), radius(r) {}

double Circle::calculateArea() const {
    return PI * radius * radius;
} //площадь круга

std::string Circle::getType() const {
    return "Circle";
}

Triangle::Triangle(Point a, Point b, Point c) : a(a), b(b), c(c) {}

double Triangle::calculateArea() const {
    double ab = dist(a, b), bc = dist(b, c), ca = dist(c, a);
    double s = (ab + bc + ca) / 2;
    return sqrt(s * (s - ab) * (s - bc) * (s - ca));
} //формула Герона - треугольник

std::string Triangle::getType() const {
    return "Triangle";
}

Rectangle::Rectangle(Point a, Point b, Point c, Point d) : a(a), b(b), c(c), d(d) {}

double Rectangle::calculateArea() const {
    return dist(a, b) * dist(b, c);
} //перемножаем стороны

std::string Rectangle::getType() const {
    return "Rectangle";
}

Polygon::Polygon(const std::string& filename) {
    std::ifstream in(filename);
    double x, y;
    while (in >> x >> y) {
        vertices.push_back(Point(x, y));
    }
    in.close();
} //чтение точек из файла

double Polygon::calculateArea() const {
    double area = 0.0;
    for (size_t i = 0; i < vertices.size(); i++) {
        const Point& p1 = vertices[i];
        const Point& p2 = vertices[(i + 1) % vertices.size()];
        area += (p1.x * p2.y - p2.x * p1.y);
    }
    return std::abs(area) / 2.0;
} //формула площади многоугольника

std::string Polygon::getType() const {
    return "Polygon";
}

bool Polygon::isScribble() const {
    return vertices.size() < 3;
} //меньше 3 точек — не подходит
