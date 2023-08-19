COMP5421 Assignment #4
Submitted by: Eric Spensieri (ID #26997252)
==================

The Shape hierarchy project is an implementation of a C++ program that defines a class hierarchy to represent different shapes. It allows the user to create and manipulate various shapes including rectangles, rhombuses, and two types of triangle. The program provides functionalities to calculate the area, perimeter, and draw the shapes on a canvas object.

Classes
=============

The project includes the following classes:

Shape: 	
The base class that represents a generic shape. It contains common properties like the shape's name, height, width, and pen character. The class defines virtual functions to calculate the area and perimeter of the shape, as well as functions to draw the shape on a canvas.

Rectangle: 
A derived class from Shape, representing a rectangle. It overrides the virtual functions of Shape to provide specific implementations for area and perimeter calculations.

Triangle: 
A derived class from Shape, representing a triangle. It is an abstract class, and its derived classes, AcuteTriangle and RightTriangle, provide specific implementations for area and perimeter calculations.

AcuteTriangle: 
A derived class from Triangle, representing an acute triangle. It overrides the virtual functions of Shape and Triangle to provide specific implementations for area and perimeter calculations.

RightTriangle: 
A derived class from Triangle, representing a right triangle. It overrides the virtual functions of Shape and Triangle to provide specific implementations for area and perimeter calculations.

Rhombus: 
A derived class from Shape, representing a rhombus. It overrides the virtual functions of Shape to provide specific implementations for area and perimeter calculations.

Canvas: 
A class that represents a 2D canvas on which shapes can be drawn. It provides functionalities to draw different shapes on the canvas and overlap them.


Usage
==============
To use the Shape hierarchy project, follow these steps:

Include the necessary header files for the shapes you want to create (e.g., Rectangle.h, AcuteTriangle.h, etc.) in your C++ source files.Create objects of the desired shape classes by passing the necessary parameters to their constructors (e.g., name, height, width, etc.). If needed, create a canvas object to draw the shapes on it using the draw function of the shape objects and the overlap function of the canvas.

Compile and run your C++ program to see the results and interact with the shapes.A test driver is inluded with the source files to demonstrate the shape functionality.
