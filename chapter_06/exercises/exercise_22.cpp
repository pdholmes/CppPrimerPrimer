/*
Exercise 6.22 on p. 219
Write a function to swap two int pointers
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void swap_pointers (int*& p1, int*& p2) {
	int *tmp = p1;
	p1 = p2;
	p2 = tmp;
}

int main(int argc, char const *argv[])
{
	int i1 = 19, i2 = 91;
	int* p1 = &i1;
	int* p2 = &i2;
	cout << *p1 << " " << *p2 << endl;
	swap_pointers(p1, p2);
	cout << *p1 << " " << *p2 << endl;
	return 0;
}