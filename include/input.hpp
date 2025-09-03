#ifndef INPUT_HPP
#define INPUT_HPP
#include "elements.hpp"

struct Input {
	int _getch = 0;
	void get_input(bool &running, Bird &bird);
};

#endif
