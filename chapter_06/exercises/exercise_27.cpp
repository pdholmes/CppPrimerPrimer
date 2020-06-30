/*
Exercise 6.27 on p. 222
Write a function that takes an initializer_list<int> and produces
the sum of elements in the list.
*/

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::initializer_list;

int sum(initializer_list<int> li) {
	int sum = 0;
	for (const int &i : li)
		sum += i;
	return sum;
}

int main(int argc, char const *argv[])
{
	int i1 = 0, i2 = 0, i3 = 0;
	cout << "Give me some ints!!! I'll sum them :)" << endl;
	cin >> i1 >> i2 >> i3;
	cout << "The sum is " << sum({i1, i2, i3}) << endl;
}