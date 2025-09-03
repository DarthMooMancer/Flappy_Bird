#include <iostream>
#include <thread>
#include "window.hpp"
#include "input.hpp"

int main() {
	Window window;
	Input input;
	bool running = true;

	std::thread input_thread(&Input::get_input, &input, std::ref(running));
	
	while (running) {
		window.update_display();
	}

	input_thread.join();

	return 0;
}
