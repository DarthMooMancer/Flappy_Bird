#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "window.hpp"
#include "input.hpp"
#include "elements.hpp"

void _add_pipe(std::vector<Pipe> &p) {
	p.push_back(Pipe());
}

void _delete_pipe(std::vector<Pipe> &p) {
	p.erase(p.begin());
}

int main() {
	std::srand(std::time(0));
	Window window;
	Input input;
	Bird bird;
	bool running = true;
	bool pause = false;
	int frames = 0;
	std::vector<Pipe> pipes;

	std::thread input_thread(&Input::get_input, &input, std::ref(running), std::ref(pause), std::ref(bird));
	_add_pipe(pipes);
	
	while (running) {
		if(pause) {
			continue;
		}
		bird.move();
		bird.check_collision();
		for(int i = 0; i < pipes.size(); i++) {
			pipes.at(i).move();
		}
		if(pipes.front().m_nodes->m_col < 3) {
			_delete_pipe(pipes);
		}
		for(int i = 0; i < pipes.front().m_size; i++) {
			if(pipes.front().m_nodes[i].m_col == bird.m_body.m_col) {
				if(pipes.front().m_nodes[i].m_row == bird.m_body.m_row) {
					running = false;
					std::cout << "You died!" << std::endl;
				}
			}
		}
		window.update_display(bird, pipes);
		frames++;
		if(frames > 4) {
			_add_pipe(pipes);
			frames = 0;
		}
	}

	input_thread.join();

	return 0;
}
