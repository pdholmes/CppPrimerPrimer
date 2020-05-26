// checking const int references

#include <iostream>
int main () {
	double i = 42.4;
	const int &r1 = i;
	i = 19.2;
	std::cout << r1 << std::endl;
	return 0;
}