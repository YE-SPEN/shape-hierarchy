// Shape.cpp
// Purpose: Implement Shape Base Class Members

/* ******************************************
 * @authors: Eric Spensieri
 * @version: 1.0
 * @since: July 13, 2023
 ******************************************** */

#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <typeinfo>
#include <sstream>
#include "Canvas.h"
#include "Shape.h"

using std::string;
using std::ostream;
using std::endl;
using std::left;
using std::setw;
using std::setprecision;
using std::fixed;

// Initialize the static member variable for Shape IDs
size_t Shape::nextId = 1;

// custom constructor
Shape::Shape(size_t height, size_t width, string name, char pen) : name(name), height(height), width(width), pen(pen) {
    id = nextId++;
}

// validate dimension value is even
bool Shape::isEven(size_t value) {
    return (value % 2 == 0);
}

// accessors and mutators
string Shape::getName() const { 
    return name; 
}

char Shape::getPen() const { 
    return pen; 
}

size_t Shape::getHeight() const { 
    return height; 
}

size_t Shape::getWidth() const { 
    return width; 
}

size_t Shape::getID() const {
    return id;
}

void Shape::setName(string newName) {
	name = newName;
}

void Shape::setPen(char newPen) {
	pen = newPen;
}

void Shape::setHeight(size_t newHeight) {
    height = newHeight;
}

void Shape::setWidth(size_t newWidth) {
    width = newWidth;
}

// explicit toString representation 
string Shape::toString() const {
    std::stringstream os;
    os << "Shape Information" << "\n";
    os << "=================" << "\n";
    os << left << setw(23) << "Shape ID:" << id << "\n";
    os << left << setw(23) << "Shape Name:" << name << "\n";
    os << left << setw(23) << "Pen Character:" << pen << "\n";
    os << left << setw(23) << "Height:" << height << "\n";
    os << left << setw(23) << "Width:" << width << "\n";
    os << left << setw(23) << "Textual Area:" << areaScr() << "\n";
    os << left << setw(23) << "Geometric Area:" << fixed << setprecision(2) << areaGeo() << "\n";
    os << left << setw(23) << "Textual Perimeter:" << perimeterScr() << "\n";
    os << left << setw(23) << "Geometric Perimeter:" << fixed << setprecision(2) << perimeterGeo() << "\n";

    os << left << setw(23) << "Static Type:" << typeid(this).name() << "\n";
    os << left << setw(23) << "Dynamic Type:" << typeid(*this).name() << "\n";

    return os.str();
}

// implicit toString representation
ostream& operator<<(ostream& os, const Shape& shape) {
    os << shape.toString();
    return os;
}

