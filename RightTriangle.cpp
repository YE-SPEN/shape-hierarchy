// RightTriangle.cpp
// Purpose: Implement Right Triangle Derived Class Members

/* ******************************************
 * @authors: Eric Spensieri
 * @version: 1.0
 * @since: July 13, 2023
 ******************************************** */

#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "Canvas.h"
#include "Triangle.h"
#include "RightTriangle.h"

using std::string;
using std::ostream;
using std::sqrt;

// custom constructor
RightTriangle::RightTriangle(size_t base, string name, char pen) : Triangle(base, base, name, pen) {}

// textual area
int RightTriangle::areaScr() const {
	return getHeight() * ( getHeight() + 1 ) / 2;
}

// geometric perimeter
double RightTriangle::perimeterGeo() const {
	return ( 2 + sqrt(2) ) * getHeight();
}

// textual perimeter
int RightTriangle::perimeterScr() const {
	if (getHeight() == 1) {
		return 1;
	}
	return 3 * ( getHeight() - 1 );
}

// draw right triangle to canvas
Canvas RightTriangle::draw() {
	Canvas newRT(static_cast<int>(getHeight()), static_cast<int>(getWidth()), ' ');

	int row = 0;
	int range = 0;

	// use an incrementing range to draw 1, then 2, then 3 pen characters per row and so on
	while (row <= newRT.getRows() - 1) {
		for (int column = 0; column <= range; column++) {
			newRT.put(row, column, getPen());
		}
		range++;
		row++;
	}

	return newRT;
}

