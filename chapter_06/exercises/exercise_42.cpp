/*
Exercise 6.42 on p. 238
*/

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
	return (ctr > 1) ? word + ending : word;
}

int main(int argc, char const *argv[])
{
	string s1 = "success";
	string s2 = "failure";

	cout << make_plural(2, s1, "es") << endl;
	cout << make_plural(2, s2) << endl;
	return 0;
}