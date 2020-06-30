/*
Exercise 6.44 on p. 238
Rewriting isShorter to be inline
*/

#include <string>
#include <iostream>
#include "exercise_44.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
	string s1 = "pee";
	string s2 = "poop";
	cout << "Is " << s1 << " shorter than " << s2 << "?" << endl;
	cout << (isShorter(s1, s2) ? "True" : "False") << endl;

	return 0;
}