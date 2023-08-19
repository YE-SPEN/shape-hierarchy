// Triangle.h
// Purpose: Define Triangle Base Class member functions

/* ******************************************

 * @authors: Eric Spensieri
 * @version: 1.0
 * @since: July 12, 2023

 ******************************************** */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <ostream>
#include <string>
#include "Canvas.h"
#include "Shape.h"

using std::string;
using std::ostream;

class Triangle: public Shape {

public:
    // custom constructor
    Triangle(size_t base, size_t height, string name, char pen);

    // shape operations
    double areaGeo() const override;
    virtual int areaScr() const = 0;
    virtual double perimeterGeo() const = 0;
    virtual int perimeterScr() const = 0;
    virtual Canvas draw() = 0;

};

#endif
