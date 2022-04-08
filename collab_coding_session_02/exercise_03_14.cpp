// Write a program to read a sequence of ints from cin and store
// those values in a vector.

#include <string>
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main() {
	vector<int> ivec;
	int i = 0;
	while (cin >> i) {
		ivec.push_back(i);
	}

	for (const auto i2 : ivec) {
		cout << i2 << " ";
	}
	cout << endl;
}