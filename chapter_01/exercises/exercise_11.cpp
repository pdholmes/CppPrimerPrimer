/*
Exercise 1.11 on p. 13
Write a program that prompts the user for two integers. Print each
number in the range specified by those integers.
*/

#include <iostream>

int main() {
	int v1 = 0, v2 = 0;
	std::cout << "Give me two integers! The first less than the second" << std::endl;
	std::cin >> v1 >> v2;
	while (v1 <= v2) {
		std::cout << v1 << " ";
		++v1;
	}
	std::cout << std::endl;
	return 0;
}