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

	std::thread input_thread(&Input::get_input, &input, std::ref(running), std::ref(bird));
	
	while (running) {
		window.update_display(bird);
	}

	input_thread.join();

	return 0;
}
