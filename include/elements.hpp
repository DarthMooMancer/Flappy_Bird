#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include "globals.hpp"

struct Point {
	Point() : m_row(0), m_col(0) {};
	Point(int row, int col) : m_row(row), m_col(col) {};
	int m_row;
	int m_col;
	void assign(int row, int col);
	void to_string();
};

struct Bird {
	Bird() : m_fly(false) {};
	Point m_body {(ROW/2), 4};
	bool m_fly;
	void move();
	void check_collision();
};

struct Pipe {
	Pipe();
	int m_size;
	Point m_nodes[ROW];
	void move();
};

#endif
