#include <iostream>
#include "arrayt.hpp"


int main() {
	ArrayT<double> arr(5);

	for (ptrdiff_t i = 0; i < 5; ++i) {
		arr[i] = 1.0;
	}

	std::cout << std::endl;
	for (ptrdiff_t i = 0; i < arr.ssize(); ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	arr.resize(6);
	arr[5] = 6;
	for (ptrdiff_t i = 0; i < arr.ssize(); ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	arr.resize(5);
	for (ptrdiff_t i = 0; i < arr.ssize(); ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	arr.remove(3);
	for (ptrdiff_t i = 0; i < arr.ssize(); ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	arr.insert(2, 15);
	for (ptrdiff_t i = 0; i < arr.ssize(); ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}