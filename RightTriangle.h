// RightTriangle.h
// Purpose: Define Right Triangle Derived Class member functions

/* ******************************************

 * @authors: Eric Spensieri
 * @version: 1.0
 * @since: July 14, 2023

 ******************************************** */

#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include <iostream>
#include <ostream>
#include <string>
#include "Canvas.h"
#include "Triangle.h"

using std::string;
using std::ostream;

class RightTriangle : public Triangle {

public:
    // custom constructor
    RightTriangle(size_t base, string name = "Ladder", char pen = '*');

    // shape operations
    int areaScr() const override;
    double perimeterGeo() const override;
    int perimeterScr() const override;
    Canvas draw() override;

};

#endif
