/*
Exercise 2.18 on p. 56
Write code to change the value of a pointer. Write code to change the
value to which the pointer points.
*/

#include <iostream>

int main() {
	int i = 42, i2 = 19;
	int *ip = &i;
	std::cout << "The address of ip is " << ip << std::endl;
	ip = &i2;
	std::cout << "The new address of ip is " << ip << std::endl;

	std::cout << "The value of ip is " << *ip << std::endl;
	*ip = ++(*ip);
	std::cout << "The new value of ip is " << *ip << std::endl;
}