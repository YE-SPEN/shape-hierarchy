// Canvas.cpp
// Purpose: Implement Shape Base Class Members

/* ******************************************
 * @authors: Eric Spensieri
 * @version: 1.0
 * @since: July 14, 2023
 ******************************************** */

#include <iostream>
#include <ostream>
#include <istream>
#include <array>
#include <vector>
#include "Canvas.h"

using std::array;
using std::ostream;
using std::istream;
using std::vector;
using std::string;
using std::endl;

// custom constructor
Canvas::Canvas(int rows, int columns, char fillChar) : fillChar(fillChar), grid(rows, vector<char>(columns, fillChar)) {}

// validate dimensions
bool Canvas::check(int r, int c) const {
	return (r > 0 && c > 0);
}

// resize canvas
void Canvas::resize(size_t rows, size_t columns) {
	grid.resize(rows, vector<char>(columns, fillChar));
}

// accessor and mutators
char Canvas::getFillChar() const {
	return fillChar;
}

void Canvas::setFillChar(char ch) {
	fillChar = ch;
}

int Canvas::getRows() const {
	return grid.size();
}

int Canvas::getColumns() const {
	if (!grid.empty()) {
		return grid[0].size();
	}
	return 0;
}

// inversion functions
Canvas Canvas::flip_horizontal() const {
	Canvas flippedOnX(*this);
	for (vector<char>& row : flippedOnX.grid) {
		std::reverse(row.begin(), row.end());
	}
	return flippedOnX;
}

Canvas Canvas::flip_vertical() const {
	Canvas flippedOnY(*this);
	std::reverse(flippedOnY.grid.begin(), flippedOnY.grid.end());

	return flippedOnY;
}

// print canvas grid
void Canvas::print(ostream& os) const {
	for (const vector<char>& row : grid) {
		for (char ch : row) {
			os << ch;
		}
		os << endl;
	}
}

// get & put index functions
char Canvas::get(int r, int c) const {
	return grid[r][c];
}

void Canvas::put(int r, int c, char ch) {
	grid[r][c] = ch;
}

void Canvas::drawString(int r, int c, const string text) {
	for (char ch : text) {
		if (c >= getColumns()) {
			return;
		}
		grid[r][c] = ch;
		c++;
	}
}

void Canvas::overlap(const Canvas& can, size_t r, size_t c) {
	int rowNum = 0;
	for (const vector<char>& row : can.grid) {
		if (r >= getRows()) {
			break;
		}
		int colNum = 0;
		for (char ch : row) {
			if (c >= getColumns()) {
				break;
			}
			put(r, c, can.get(rowNum, colNum));
			colNum++;
			c++;
		}
		rowNum++;
		r++;
		c -= colNum;
	}
}


// output overload
ostream& operator<<(ostream& os, const Canvas& can) {
	can.print(os);
	return os;
}

