#include <ncurses.h>
#include <iostream>
#include "input.hpp"

void Input::get_input(bool &running, bool &pause, Bird &bird) {
	while(running) {
		initscr();
		cbreak();
		noecho();

		_getch = getch();
		std::cout << _getch << std::endl;

		endwin();
		if(_getch == 32) {
			bird.m_fly = true;
		}
		if(_getch == 112) {
			if(pause) {
				pause = false;
				_getch = 0;
			} else {
				pause = true;
				_getch = 0;
			}
		}
		if(_getch == 113) {
			running = false;
		}
	}
}
