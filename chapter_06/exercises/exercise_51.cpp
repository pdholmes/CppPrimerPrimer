/*
Exercise 6.51 on p. 245
Write all four versions of f, test the examples
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void f()
{
	cout << "Hello you called f()" << endl;
}

void f(int i1)
{
	cout << "Hello you called f(int)" << endl;
}

void f(int i1, int i2)
{
	cout << "Hello you called f(int, int)" << endl;
}

void f(double i1, double i2 = 3.14)
{
	cout << "Hello you called f(double, double=3.14)" << endl;
}

int main(int argc, char const *argv[])
{
	cout << "(a): " << endl;
	// f(2.56, 42);
	cout << "(b): " << endl;
	f(42);
	cout << "(c): " << endl;
	f(42, 0);
	cout << "(d): " << endl;
	f(2.56, 3.14);

	return 0;
}