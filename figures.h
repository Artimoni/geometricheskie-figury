#pragma once
#include <vector>
#include <string>

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
}; //структура точки

class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual std::string getType() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    Point center;
    double radius;
public:
    Circle(Point c, double r);
    double calculateArea() const override;
    std::string getType() const override;
}; //круг с центром и радиусом

class Triangle : public Shape {
    Point a, b, c;
public:
    Triangle(Point a, Point b, Point c);
    double calculateArea() const override;
    std::string getType() const override;
};//треугольник по 3 точкам

class Rectangle : public Shape {
    Point a, b, c, d;
public:
    Rectangle(Point a, Point b, Point c, Point d);
    double calculateArea() const override;
    std::string getType() const override;
}; //прямоугольник по 4 точкам

class Polygon : public Shape {
    std::vector<Point> vertices;
public:
    Polygon(const std::string& filename);
    double calculateArea() const override;
    std::string getType() const override;
    bool isScribble() const;
}; //многоугольник из файла
    
