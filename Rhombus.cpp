// Rhombus.cpp
// Purpose: Implement Rhombus Derived Class Members

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
#include "Shape.h"
#include "Rhombus.h"
#include "AcuteTriangle.h"

using std::string;
using std::ostream;
using std::sqrt;

// custom constructor
Rhombus::Rhombus(size_t height, string name, char pen) : Shape(height, height, name, pen) {
	if (isEven(height)) {
		setHeight(height + 1);
		setWidth(height + 1);
	}
}

// geometric area
double Rhombus::areaGeo() const {
	return static_cast<double>( getHeight() * getWidth() ) / 2.0;
}

// textual area
int Rhombus::areaScr() const {
	double n = getHeight() / 2;
	return 2 * n * (n + 1) + 1;
}

// geometric perimeter
double Rhombus::perimeterGeo() const {
	return 2 * sqrt(2) * getHeight();
}

// textual perimeter
int Rhombus::perimeterScr() const {
	if (getHeight() == 1) {
		return 1;
	}
	return 2 * (getHeight() - 1);
}

// draw rhombus to canvas
Canvas Rhombus::draw() {
	Canvas newRhombus(static_cast<int>(getHeight()), static_cast<int>(getWidth()), ' ');

    // find the middle row of the rhombus
    int midRow = getHeight() / 2;
    
	// draw the top half using an Acute Triangle object
	AcuteTriangle topHalf{ getWidth(), "Top", getPen() };
	Canvas topHalfCanvas{ topHalf.draw() };

	// overlap the top half to the Rhombus canvas
	newRhombus.overlap(topHalfCanvas, 0, 0);

	// create the bottom half of the rhombus by flipping the top half vertically
	Canvas bottomHalfCanvas{ topHalfCanvas.flip_vertical() };

	// overlap the bottom half beginning from index 0 of the middle row
	newRhombus.overlap(bottomHalfCanvas, midRow, 0);

    return newRhombus;
}

