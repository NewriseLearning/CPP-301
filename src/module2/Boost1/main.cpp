#include "pch.h"
#include <iostream>

using namespace boost::asio;

int main() {
	io_context io;
	auto duration = chrono::seconds(5);
	auto timer = steady_timer(io, duration);
	std::cout << "Begin" << std::endl;
	timer.wait();
	std::cout << "Completed" << std::endl;
	return 0;
}