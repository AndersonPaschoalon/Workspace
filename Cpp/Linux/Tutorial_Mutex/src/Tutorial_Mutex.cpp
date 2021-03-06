//============================================================================
// Name        : Tutorial_Mutex.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
// mutex example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

std::mutex mtx;           // mutex for critical section

void print_block(int n, char c) {
	// critical section (exclusive access to std::cout signaled by locking mtx):
	mtx.lock();

	for (int i = 0; i < n; ++i) {
		std::cout << c;
	}
	std::cout << '\n';
	mtx.unlock();
}

void print_block_function(int n, char c) {
	for (int i = 0; i < n; ++i) {
		std::cout << c;
	}
	std::cout << '\n';
}

int main() {

	std::thread th1(print_block, 50, '*');
	std::thread th2(print_block, 50, '$');

	mtx.lock();
	std::thread th3(print_block_function, 50, '#');
	mtx.unlock();
	mtx.lock();
	std::thread th4(print_block_function, 50, '@');
	mtx.unlock();

	th1.join();
	th2.join();
	th3.join();
	th4.join();

	return 0;
}
