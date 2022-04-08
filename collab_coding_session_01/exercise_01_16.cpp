/*
Exercise 1.16 on p. 17
Write your own version of a program that prints the sum of a set of 
integers read from cin.
*/

#include<iostream>
int main() {
	std::cout << "Give me numbers!" << std::endl;
	int value = 0;
	int sum = 0;
	while (std::cin >> value) {
		sum += value;
	}
	std::cout << "Sum is: " << sum << std::endl;
	return 0;
}