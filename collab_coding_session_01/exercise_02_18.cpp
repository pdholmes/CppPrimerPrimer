/*
Exercise 2.18 on p. 56
Write code to change the value of a pointer. Write code to change the
value to which the pointer points.
*/

#include <iostream>
int main () {
	int i = 42, i2 = 19;
	int *p = &i;
	std::cout << "The address held by p is " << p << std::endl;
	p = &i2;
	std::cout << "The new address held by p is " << p << std::endl;

	std::cout << "The value of the object pointed to by p is " << *p << std::endl;
	*p = ++(*p);
	std::cout << "The new value of the object pointed to by p is " << *p << std::endl;

	return 0;
}