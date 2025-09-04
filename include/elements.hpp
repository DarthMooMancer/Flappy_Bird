#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include "globals.hpp"

struct Point {
	Point() : m_row(0), m_col(0) {};
	Point(int row, int col) : m_row(row), m_col(col) {};
	int m_row;
	int m_col;
};

struct Bird {
	Bird() : m_fly(false) {};
	Point m_body {(ROW/2), 2};
	bool m_fly;
	void move();
};

#endif
