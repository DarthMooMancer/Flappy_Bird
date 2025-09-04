#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "window.hpp"
#include "input.hpp"
#include "elements.hpp"

int main() {
	std::srand(std::time(0));
	Window window;
	Input input;
	Bird bird;
	bool running = true;
	bool pause = false;
	int frames = 0;

	std::vector<Pipe> pipes = { Pipe() };
	std::thread input_thread(&Input::get_input, &input, std::ref(running), std::ref(pause), std::ref(bird));
	
	while (running) {
		bird.move();
		bird.check_collision();
		if(pause) {
			continue;
		}
		for(int i = 0; i < pipes.size(); i++) {
			pipes.at(i).move();
		}
		if(pipes.front().m_nodes->m_col < 3) {
			pipes.erase(pipes.begin());
		}
		if(bird.m_body.m_row >= ROW - 1) {
			running = false; 
			std::cout << "You died! Your score is: " << bird.m_score << std::endl;
		}
		for(int j = 0; j < pipes.size(); j++) {
			for(int i = 0; i < pipes.front().m_size; i++) {
				if(pipes.at(j).m_nodes[i].m_col != bird.m_body.m_col) continue;
				if(pipes.at(j).m_nodes[i].m_row != bird.m_body.m_row) continue;
				if(pipes.at(j).m_nodes[i].m_symbol == ' ') continue;
				running = false;
				std::cout << "You died! Your score is: " << bird.m_score << std::endl;
			}
		}
		window.update_display(bird, pipes);
		frames++;
		if(pipes.front().m_nodes->m_col == bird.m_body.m_col) {
			bird.m_score++;
		}
		if(frames > 4) {
			pipes.push_back(Pipe());
			frames = 0;
		}
	}

	input_thread.join();

	return 0;
}
