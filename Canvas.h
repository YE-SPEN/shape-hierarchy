// Canvas.h
// Purpose: Define Canvas ADT member functions

/* ******************************************

 * @authors: Eric Spensieri
 * @version: 1.0
 * @since: July 12, 2023

 ******************************************** */

#ifndef CANVAS_H
#define CANVAS_H

#include <iostream>
#include <ostream>
#include <istream>
#include <array>
#include <vector>

using std::array;
using std::ostream;
using std::istream;
using std::vector;

class Canvas {

	public:
		Canvas() = default;
		virtual ~Canvas() = default;
		Canvas(const Canvas&) = default;
		Canvas(Canvas&&) = default;
		Canvas& operator=(const Canvas&) = default;
		Canvas& operator=(Canvas&&) = default;

	protected:
		vector<vector<char>> grid{}; // a 2D vector representing a canvas
		char fillChar{ ' ' }; // fill or clear character
		bool check(int r, int c) const; // validates row r and column c, 0-based
		void resize(size_t rows, size_t columns); // resizes this Canvas’s dimensions

	public:
		// creates this canvas’s (rows x columns) grid filled with blank characters
		Canvas(int rows, int columns, char fillChar = ' ');
		char getFillChar()const;
		void setFillChar(char ch);
		int getRows()const; // returns height of this Canvas object
		int getColumns()const; // returns width of this Canvas object
		Canvas flip_horizontal() const; // flips this canvas horizontally
		Canvas flip_vertical() const; // flips this canvas vertically
		void print(ostream&) const; // prints this Canvas to ostream
		char get(int r, int c) const; // returns char at row r and column c, 0-based;
		void put(int r, int c, char ch); // puts ch at row r and column c, 0-based;
		void drawString(int r, int c, const std::string text);
		void overlap(const Canvas & can, size_t r, size_t c);
};

ostream& operator<< (ostream & sout, const Canvas & can);

#endif