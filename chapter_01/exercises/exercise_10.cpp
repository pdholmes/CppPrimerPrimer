/*
Exercise 1.10 on p. 13
In addition to the ++ operator that adds 1 to its operand, there is a
decrement operator (--) that subtracts 1. Use the decrement operator
to write a while that prints the numbers from ten down to zero.
*/
#include <iostream>

int main() {
	int val = 10;
	while (val >= 0) {
		std::cout << val << " ";
		--val;
	}
	return 0;
}