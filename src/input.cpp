#include <ncurses.h>
#include "input.hpp"

void Input::get_input(bool &running) {
	while(running) {
		initscr();
		cbreak();
		noecho();

		_getch = getch();

		endwin();
		if(_getch == 113) {
			running = false;
		}
	}
}
