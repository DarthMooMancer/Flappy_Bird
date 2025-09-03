#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

struct Point {
	Point();
	Point(int row, int col) : m_row(row), m_col(col) {};
	int m_row;
	int m_col;
};

struct Bird {
	Point m_body;
};

#endif
