/*
Exercise 1.04 on p. 9
Our program used the addition operator, +, to add two numbers. Write a
program that uses the multiplication operator *, to print the product
instead.
*/

#include<iostream>

int main() {
	std::cout << "Enter two numbers! :" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The product is: " << v1 * v2 << std::endl;
	return 0;
}