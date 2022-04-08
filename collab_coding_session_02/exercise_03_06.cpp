// Use a range for to change all the characters in a string to X.

#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
	string s1;
	cout << "Type something" << endl;
	cin >> s1;
	for (auto &c : s1) {
		c = 'X';
	}
	cout << s1 << endl;
}