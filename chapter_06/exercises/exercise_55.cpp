/*
Exercise 6.55 and 6.56 on p. 245
Write four functions that add, subtract, multiply, and divide two int
values. Store pointers to these functions in your vector from the previous
exercise.
*/

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int add(int i1, int i2)
{
	return i1 + i2;
}

int subtract(int i1, int i2)
{
	return i1 - i2;
}

int multiply(int i1, int i2)
{
	return i1 * i2;
}

int divide(int i1, int i2)
{
	return i1 / i2;
}

int main(int argc, char const *argv[])
{
	using func = decltype(add)*;
	vector<func> v = {add, subtract, multiply, divide};

	for (auto p : v)
		cout << p(20, 10) << endl;
}