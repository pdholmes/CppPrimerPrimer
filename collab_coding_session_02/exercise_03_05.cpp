// Write a program to read strings from the standard input,
// concatenating what is read into one large string. Print the
// concatenated string. Next, change the program to separate
// adjacent input strings by a space.

#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() { 
	string word, total;
	while (cin >> word) { 
		total += word;
		total += " ";
	}
	cout << total << endl;
}