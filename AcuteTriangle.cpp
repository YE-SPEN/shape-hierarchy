// AcuteTriangle.cpp
// Purpose: Implement Right Triangle Derived Class Members

/* ******************************************
 * @authors: Eric Spensieri
 * @version: 1.0
 * @since: July 14, 2023
 ******************************************** */

#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "Canvas.h"
#include "Triangle.h"
#include "AcuteTriangle.h"

using std::string;
using std::ostream;
using std::sqrt;

// custom constructor
AcuteTriangle::AcuteTriangle(size_t base, string name, char pen) : Triangle(base, base, name, pen) {
	if (isEven(base)) {
		setWidth(base + 1);
	}
	setHeight(( getWidth() + 1 ) / 2);
}

// textual area
int AcuteTriangle::areaScr() const {
	return getHeight() * getHeight();
}

// geometric perimeter
double AcuteTriangle::perimeterGeo() const {
	double n = (getWidth() * getWidth()) + (4 * getHeight() * getHeight());
		return getWidth() + sqrt(n);
}

// textual perimeter
int AcuteTriangle::perimeterScr() const {
	if (getHeight() == 1) {
		return 1;
	}
	return 4 * (getHeight() - 1);
}

// draw acute triangle to canvas
Canvas AcuteTriangle::draw() {
	Canvas newAT(static_cast<int>(getHeight()), static_cast<int>(getWidth()), ' ');

	int row = newAT.getRows() - 1;
	int i = 0;
	int j = newAT.getColumns() - 1;

	// draw from bottom row up
	while (row >= 0) {
		while (i <= j) {
			newAT.put(row, i, getPen());
			i++;
		}
		row--;
		j--;
		i = newAT.getColumns() - j - 1;
	}

	return newAT;
}

