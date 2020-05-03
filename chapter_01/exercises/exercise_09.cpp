/*
Exercise 1.09 on p. 13
Write a program that uses a while to sum the numbers from 50 to 100
*/
#include <iostream>

int main() {
	int sum = 0;
	int val = 50;
	while (val <= 100) {
		sum += val;
		++val;
	}
	std::cout << sum << std::endl;
	return 0;
}