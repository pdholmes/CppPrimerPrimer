// Write a program to read two strings and report whether the strings
// are equal. If not, report which of the two is larger. Now, change
// the program to report whether the strings have the same length, and
// if not, report which is longer.

#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
	cout << "Enter two strings" << endl;
	string s1, s2;
	cin >> s1 >> s2;
	// if (s1 == s2) {
	// 	cout << "Strings are equal" << endl;
	// }
	// else { 
	// 	cout << (s1 > s2 ? s1 : s2) << " is larger" << endl;
	// }
	if (s1.size() == s2.size()) {
		cout << "Strings are equal in length" << endl;
	}
	else {
		cout << (s1.size() > s2.size() ? s1 : s2) << " is longer" << endl;
	}
}