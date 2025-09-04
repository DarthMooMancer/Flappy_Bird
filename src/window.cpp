#include "window.hpp"
#include <iostream>
#include <chrono>
#include <thread>

void Window::tick(int fps) {
	std::this_thread::sleep_for(std::chrono::milliseconds(fps)); // 1000 / fps; 200ms = 5fps
}

void Window::update_display(Bird &bird, std::vector<Pipe> pipes) {
	for(std::array<char, COL> &row : m_board) { row.fill('.'); }

	m_board[bird.m_body.m_row][bird.m_body.m_col] = bird.m_body.m_symbol;
	for(int i = 0; i < pipes.size(); i++) {
		for(int j = 0; j < pipes.front().m_size; j++) {
			if(pipes.at(i).m_nodes[j].m_symbol == '|') {
				m_board[pipes.at(i).m_nodes[j].m_row][pipes.at(i).m_nodes[j].m_col] = pipes.at(i).m_nodes[j].m_symbol;
			}
		}
	}

	std::cout << "\033[H" << std::flush;
	for(std::array<char, COL> &row : m_board) {
		for(char &col : row) {
			std::cout << col << " ";
		}
		std::cout << "\r\n";
	}
	tick(200);
}
