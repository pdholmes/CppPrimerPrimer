/*
Exercise 6.23 on p. 219
Write your own versions of each of the print functions
presented in this section. Call each of these functions
to print i and j defined as follows:
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void print (const int i) {
	cout << i << endl;
}

void print (const int *beg, const int *end) {
	while (beg != end)
		cout << *beg++ << endl;
}

void print (const int ia[], size_t sz) {
	for (decltype(sz) i = 0; i != sz; ++i)
		cout << ia[i] << endl;
}

void print (const int (&ia)[2]) {
	for (auto i : ia)
		cout << i << endl;
}

int main(int argc, char const *argv[])
{
	int i = 0, j[2] = {0, 1};
	print(i);
	print(std::begin(j), std::end(j));
	print(j, std::end(j) - std::begin(j));
	print(j);

}