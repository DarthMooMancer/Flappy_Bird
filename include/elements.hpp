#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include "globals.hpp"

struct Point {
	Point() : m_row(0), m_col(0), m_symbol(' ') {};
	Point(int row, int col, char symbol) : m_row(row), m_col(col), m_symbol(symbol) {};
	int m_row;
	int m_col;
	char m_symbol;
	void assign(int row, int col);
};

struct Bird {
	Bird() : m_fly(false) {};
	Point m_body { (ROW/2), 4, '*' };
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
