#include <iostream>
#include <thread>
#include "window.hpp"
#include "input.hpp"
#include "elements.hpp"

int main() {
	Window window;
	Input input;
	Bird bird;
	bool running = true;
	bool pause = false;

	std::thread input_thread(&Input::get_input, &input, std::ref(running), std::ref(pause), std::ref(bird));
	
	while (running) {
		if(pause) {
			continue;
		}
		bird.move();
		window.update_display(bird);
	}

	input_thread.join();

	return 0;
}
