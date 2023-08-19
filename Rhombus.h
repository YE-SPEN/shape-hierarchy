// Rectangle.h
// Purpose: Define derived class for Rhombus

/* ******************************************

 * @authors: Eric Spensieri
 * @version: 1.0
 * @since: July 13, 2023

 ******************************************** */

#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <iostream>
#include <ostream>
#include <string>
#include "Canvas.h"
#include "Shape.h"

using std::string;
using std::ostream;

class Rhombus : public Shape {

public:
    // custom constructor
    Rhombus(size_t height, string name = "Diamond", char pen = '*');

    // mutators & accessors
    double areaGeo() const override;
    int areaScr() const override;
    double perimeterGeo() const override;
    int perimeterScr() const override;
    Canvas draw() override;

};

#endif
