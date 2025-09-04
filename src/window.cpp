#include "window.hpp"
#include <iostream>
#include <chrono>
#include <thread>

void Window::tick(int fps) {
	std::this_thread::sleep_for(std::chrono::milliseconds(fps)); // 1000 / fps; 200ms = 5fps
}

void Window::update_display(Bird &bird) {
	for(std::array<char, COL> &row : m_board) { row.fill('.'); }

	m_board[bird.m_body.m_row][bird.m_body.m_col] = '*';

	std::cout << "\033[H" << std::flush;
	for(std::array<char, COL> &row : m_board) {
		for(char &col : row) {
			std::cout << col << " ";
		}
		std::cout << "\r\n";
	}
	tick(200);
}
