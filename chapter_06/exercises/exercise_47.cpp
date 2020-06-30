/*
Exercise 6.33 on p. 228
Write a recursive function to print the contents of a vector.
for Exercise 6.47, revise to use a debug mode to print the size of the
vector on each call.
*/

// #define NDEBUG // uncomment this to turn off debugging 

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void print(vector<int>::const_iterator it, vector<int>::const_iterator end) {
	#ifndef NDEBUG
		cout << "Size: " << (end - it) << endl;
	#endif

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