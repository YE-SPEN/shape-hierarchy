// Rectangle.cpp
// Purpose: Implement Rectangle Derived Class Members

/* ******************************************
 * @authors: Eric Spensieri
 * @version: 1.0
 * @since: July 13, 2023
 ******************************************** */

#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include "Canvas.h"
#include "Shape.h"
#include "Rectangle.h"

using std::string;
using std::ostream;

// custom constructor
Rectangle::Rectangle(size_t height, size_t width, string name, char pen) : Shape(height, width, name, pen) {}

// geometric area
double Rectangle::areaGeo() const {
	return (getHeight() * getWidth());
}

// textual area
int Rectangle::areaScr() const {
	return areaGeo();
}

// geometric perimeter
double Rectangle::perimeterGeo() const {
	return 2 * (getHeight() + getWidth());
}

// textual perimeter
int Rectangle::perimeterScr() const {
	if (getHeight() == 1 || getWidth() == 1) {
		return areaGeo();
	}
	return 2 * (getHeight() + getWidth()) - 4;
}

// draw rectangle to canvas
Canvas Rectangle::draw() {
	Canvas newRect(static_cast<int>(getHeight()), static_cast<int>(getWidth()), getPen());
	return newRect;
}

