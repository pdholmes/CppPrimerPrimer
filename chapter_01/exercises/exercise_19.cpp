/*
Exercise 1.19 on p. 18
Revise the program you wrote for the exercises in Sec. 1.4.1 (p. 13)
that printed a range of numbers so that it handles input in which the
first number is smaller than the second.
*/

#include <iostream>

int main() {
	int v1 = 0, v2 = 0;
	std::cout << "Give me two integers!" << std::endl;
	std::cin >> v1 >> v2;
	if (v2 < v1) {
		int tmp = v1;
		v1 = v2;
		v2 = tmp;
	}

	while (v1 <= v2) {
		std::cout << v1 << " ";
		++v1;
	}
	std::cout << std::endl;
	return 0;
}