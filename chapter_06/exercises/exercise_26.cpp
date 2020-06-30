/*
Exercise 6.26 on p. 220
Write a program that accepts the options presented in this section.
Print the values of the arguments passed to main.
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
	// for (int i = 1; i != argc; ++i) {
	// 	cout << argv[i] << endl;
	// }
	while (*argv) {
		cout << *argv++ << endl;
	}
}