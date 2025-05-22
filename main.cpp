#include "figures.h"
#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::vector<Shape*> shapes;
    int rectangles = 0, circles = 0, triangles = 0, polygons = 0, noise = 0;
    double totalArea = 0.0;
    double circleAreaTotal = 0.0;

    shapes.push_back(new Circle(Point(0, 0), 5));
    shapes.push_back(new Triangle(Point(0, 0), Point(0, 3), Point(4, 0)));
    shapes.push_back(new Rectangle(Point(0, 0), Point(0, 3), Point(5, 3), Point(5, 0)));
    shapes.push_back(new Circle(Point(1, 1), 2.5));
    shapes.push_back(new Circle(Point(2, 2), 3.1));
    shapes.push_back(new Circle(Point(3, 3), 1.7));
    shapes.push_back(new Triangle(Point(1, 1), Point(3, 5), Point(6, 2)));
    shapes.push_back(new Triangle(Point(0, 2), Point(2, 6), Point(5, 1)));
    shapes.push_back(new Rectangle(Point(1, 1), Point(1, 4), Point(5, 4), Point(5, 1)));
    shapes.push_back(new Rectangle(Point(2, 2), Point(2, 6), Point(6, 6), Point(6, 2)));

    Polygon* poly1 = new Polygon("granitsy-uchastka2.txt");
    Polygon* poly2 = new Polygon("granitsy-uchastka2.txt");

    if (!poly1->isScribble()) shapes.push_back(poly1); else delete poly1;
    if (!poly2->isScribble()) shapes.push_back(poly2); else delete poly2;

    for (Shape* shape : shapes) {
        std::string type = shape->getType();
        double area = shape->calculateArea();

        if (type == "Rectangle") rectangles++;
        else if (type == "Circle") {
            circles++;
            circleAreaTotal += area;
        }
        else if (type == "Triangle") triangles++;
        else if (type == "Polygon") polygons++;
        else noise++;

        if (type != "Noise") {
            totalArea += area;
        }
    }
    int shapeClassesCount = 0;
    if (rectangles > 0) shapeClassesCount++;
    if (circles > 0) shapeClassesCount++;
    if (triangles > 0) shapeClassesCount++;
    if (polygons > 0) shapeClassesCount++;

    std::ofstream out("output.txt");
    out << "Rectangle = " << rectangles << "\n";
    out << "Circle = " << circles << "\n";
    out << "Triangle = " << triangles << "\n";
    out << "Polygon = " << polygons << "\n";
    out << "Noise = " << noise << "\n";
    out << "Total Area = " << totalArea << "\n";
    out << "Circle Area Total = " << circleAreaTotal << "\n";
    out << "Shape Classes Count = " << shapeClassesCount << "\n";
    out.close();

    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
