// Triangle.cpp
// Purpose: Implement Triangle Base Class Members

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
#include "Triangle.h"

using std::string;
using std::ostream;

// custom constructor
Triangle::Triangle(size_t base, size_t height, string name, char pen) : Shape(base, height, name, pen) {}

// geometric area (common for all triangles
double Triangle::areaGeo() const {
	return static_cast<double>( getHeight() * getWidth() ) / 2.0;
}

