/*
Exercise 1.16 on p. 17
Write your own version of a program that prints the sum of a set of 
integers read from cin.
*/

#include <iostream>
int main() {
	int sum = 0, value = 0;
	while (std::cin >> value) {
		sum += value;
	}
	std::cout << "Sum is: " << sum << std::endl;
	return 0;
}