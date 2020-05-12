/*
Exercise 2.04 on p. 38
Write a program to check whether your predictions were correct. If not, 
study this section until you understand what the problem is.
*/

#include <iostream>

int main() {
	unsigned u = 10, u2 = 42;
	std::cout << u2 - u << std::endl; // ok, prints 32
	std::cout << u - u2 << std::endl; // prints a really big number

	int i = 10, i2 = 42;
	std::cout << i2 - i << std::endl; // ok, prints 32;
	std::cout << i - i2 << std::endl; // ok, prints -32

	std::cout << i - u << std::endl; // ok, prints 0;
	std::cout << u - i << std::endl; // ok, prints 0;

}