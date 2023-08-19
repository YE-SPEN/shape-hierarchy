// Shape.h
// Purpose: Define Shape Base Class member functions

/* ******************************************

 * @authors: Eric Spensieri
 * @version: 1.0
 * @since: July 12, 2023

 ******************************************** */

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <ostream>
#include <string>
#include "Canvas.h"

using std::string;
using std::ostream;

class Shape {

    private:
        // common data members
        static size_t nextId;
        size_t id = 0;
        size_t height;
        size_t width;
        string name;
        char pen;

    public:
        // special members (all set to default)
        Shape() = default;
        Shape(const Shape& source) = default;
        Shape(Shape&& rhs) noexcept = default;
        virtual ~Shape() = default;
        Shape& operator=(const Shape& rhs) = default;
        Shape& operator=(Shape&& rhs) noexcept = default;

        // custom constructor
        Shape(size_t height, size_t width, string name, char pen = '*');

        // output overload
        string toString() const;
        friend ostream& operator<<(ostream& os, const Shape& shape);

        // mutators & accessors
        string getName() const;
        char getPen() const;
        size_t getHeight() const;
        size_t getWidth() const;
        size_t getID() const;
        void setName(string newName);
        void setPen(char newPen);
        void setHeight(size_t newHeight);
        void setWidth(size_t newWidth);

        // shape operations
        bool isEven(size_t value);
        virtual double areaGeo() const = 0;
        virtual int areaScr() const = 0;
        virtual double perimeterGeo() const = 0;
        virtual int perimeterScr() const = 0;
        virtual Canvas draw() = 0;

};

#endif
