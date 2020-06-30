/*
Exercise 6.21 on p. 219
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int get_larger_int (const int i, const int* p) {
	int largerint = 0;
	largerint = (i >= *p) ? i : *p;

	return largerint;
}

int main(int argc, char const *argv[])
{
	int i1 = 0, i2 = 0;
	int i3 = 0;
	cout << "Give me two ints!!" << endl;
	cin >> i1 >> i2;
	i3 = get_larger_int(i1, &i2);
	cout << i3 << " is the larger int!" << endl;
	return 0;
}

// I think I should use a const int * for p