/*
Exercise 1.13 on p. 14
Rewrite the first two exercises from Sec. 1.4.1 (p. 13) using for
loops.
*/

#include <iostream>

int main() {
	// exercise 1.09
	int sum = 0;

	for (int val = 50; val <= 100; ++val)
		sum += val;
	std::cout << sum << std::endl;

	// exercise 1.10
	for (int val = 10; val >= 0; --val)
		std::cout << val << " ";

	return 0;
}