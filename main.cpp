#include "figures.h"
#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::vector<Shape*> shapes;
    int rectangles = 0, circles = 0, triangles = 0, noise = 0;
    double totalArea = 0.0;

    shapes.push_back(new Circle(Point(0, 0), 5));
    shapes.push_back(new Triangle(Point(0, 0), Point(0, 3), Point(4, 0)));
    shapes.push_back(new Rectangle(Point(0, 0), Point(0, 3), Point(5, 3), Point(5, 0)));

    Polygon* poly = new Polygon("granitsy-uchastka2.txt");
    if (!poly->isScribble()) {
        shapes.push_back(poly);
    }
    else {
        delete poly;
    }

    for (Shape* shape : shapes) {
        std::string type = shape->getType();
        double area = shape->calculateArea();

        if (type == "Rectangle") rectangles++;
        else if (type == "Circle") circles++;
        else if (type == "Triangle") triangles++;
        else if (type == "Polygon") {}
        else noise++;

        if (type != "Noise" && type != "Polygon") {
            totalArea += area;
        }
    } //обработка и подсчёт типов и площади

    std::ofstream out("output.txt");
    out << "Rectangle = " << rectangles << "\n";
    out << "Circle = " << circles << "\n";
    out << "Triangle = " << triangles << "\n";
    out << "Noise = " << noise << "\n";
    out << "Total Area = " << totalArea << "\n";
    out.close(); //запись в файл

    for (Shape* shape : shapes) {
        delete shape;
    } //удаление всех фигур

    return 0;
}
