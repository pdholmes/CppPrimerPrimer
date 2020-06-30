/*
Exercise 6.25 on p. 220
Write a main function that takes two arguments. Concatentate
the supplied arguments and print the resulting string.
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
	string s;
	if (argc == 3) {
		for (int i = 1; i != argc; ++i) {
			s = s + argv[i];
		}
		cout << s << endl;
	}
	return 0;
}