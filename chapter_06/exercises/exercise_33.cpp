/*
Exercise 6.33 on p. 228
Write a recursive function to print the contents of a vector.
*/

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void print(vector<int>::const_iterator it, vector<int>::const_iterator end) {
	if (it == end) {
		cout << endl;
	}
	else {
		cout << *it++ << + " ";
		print(it, end);
	}
}

int main(int argc, char const *argv[])
{
	const vector<int> ivec = {1, 3, 5, 7, 9};
	print(ivec.cbegin(), ivec.cend());

	return 0;
}