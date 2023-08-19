// Rectangle.h
// Purpose: Define derived class for Rectangle

/* ******************************************

 * @authors: Eric Spensieri
 * @version: 1.0
 * @since: July 13, 2023

 ******************************************** */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <ostream>
#include <string>
#include "Canvas.h"
#include "Shape.h"

using std::string;
using std::ostream;

class Rectangle : public Shape {

public:
    // custom constructor
    Rectangle(size_t height, size_t width, string name = "Door", char pen = '*');

    // mutators & accessors
    double areaGeo() const override;
    int areaScr() const override;
    double perimeterGeo() const override;
    int perimeterScr() const override;
    Canvas draw() override;

};

#endif
