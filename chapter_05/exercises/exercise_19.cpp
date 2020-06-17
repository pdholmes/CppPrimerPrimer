/* 
Exercise 5.19 on p. 190
Write a program that uses a do while loop to repetitively request
two strings from the user and report which string is less than
the other. 
*/

#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string s1;
	string s2;
	string rsp;

	do {
		rsp.clear();
		cout << "Enter two words and I'll tell ya which one's less." << endl;
		cin >> s1 >> s2;
		cout << "The lesser word is ... " << (s1 < s2 ? s1 : s2) << "." << endl;
		cout << "Another two words? type 'y' or 'n'." << endl;
		cin >> rsp;
	}
	while (!rsp.empty() && rsp[0] != 'n');

	return 0;
}