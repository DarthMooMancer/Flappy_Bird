#include "elements.hpp"
#include <iostream>

void Point::assign(int row, int col) {
	m_row = row;
	m_col = col;
}

void Point::to_string() {
	std::cout << "(" << m_row << ", " << m_col << ")" << std::endl;
}

void Bird::move() {
	if(m_fly) {
		m_body.m_row--;
		m_fly = false;
	} else {
		m_body.m_row++;
	}
}

void Bird::check_collision() {
	if(m_body.m_row <= 0) {
		m_body.m_row = 0;
	}
}

Pipe::Pipe() {
	m_size = ROW;
	int _start = (rand() % (ROW - 3));
	for(int i = 0; i < m_size; i++) {
		m_nodes[i].assign(i, COL - 1);
		m_nodes[i].m_symbol = '|';
	}
	for(int i = _start; i < _start + 3; i++) {
		m_nodes[i].m_symbol = ' ';
	} 
}

void Pipe::move() {
	for(int i = 0; i < m_size; i++) {
		m_nodes[i].assign(m_nodes[i].m_row, m_nodes[i].m_col - 1);
	}
}
