#include "elements.hpp"

void Bird::move() {
	if(m_fly) {
		m_body.m_row--;
		m_fly = false;
	} else {
		m_body.m_row++;
	}
}
