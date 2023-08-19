// AcuteTriangle.h
// Purpose: Define Acute Triangle Derived Class member functions

/* ******************************************

 * @authors: Eric Spensieri
 * @version: 1.0
 * @since: July 14, 2023

 ******************************************** */

#ifndef ACUTETRIANGLE_H
#define ACUTETRIANGLE_H

#include <iostream>
#include <ostream>
#include <string>
#include "Canvas.h"
#include "Triangle.h"

using std::string;
using std::ostream;

class AcuteTriangle : public Triangle {

public:
    // custom constructor
    AcuteTriangle(size_t base, string name = "Wedge", char pen = '*');

    // shape operations
    int areaScr() const override;
    double perimeterGeo() const override;
    int perimeterScr() const override;
    Canvas draw() override;

};

#endif
