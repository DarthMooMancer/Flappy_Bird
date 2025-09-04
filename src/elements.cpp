#include "elements.hpp"

void Bird::move() {
	if(m_fly) {
		m_body.m_row--;
		m_fly = false;
	} else {
		m_body.m_row++;
	}
}

void Bird::check_collision() {
	if(m_body.m_row <= 0 || m_body.m_row > ROW - 1) {
		// Add velocity
	}
}
