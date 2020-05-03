/*
Exercise 1.08 on p.11
After you've predicted what will happen, test your answers by
compiling a program with each of these statements. Correct any errors
you encounter.
*/

#include <iostream>

int main() {
	std::cout << "/*";
	std::cout << "*/";
	// std::cout << /* "*/" */; <-- this line is illegal
	std::cout << /* "*/" /* "/*" */;
}