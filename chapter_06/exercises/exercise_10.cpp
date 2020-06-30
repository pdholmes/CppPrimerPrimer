/* Exercise 6.10 on p. 210 */
// using pointers, write a function to swap the values of two ints.
// test the function by calling it and printing the swapped values.
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void swapVals(int* p1, int* p2) {
	int tmp1 = *p1;
	int tmp2 = *p2;
	*p1 = tmp2;
	*p2 = tmp1;
}

int main(int argc, char const *argv[])
{
	int x1 = 0, x2 = 0;
	cout << "Type two numbers and we'll swap the value!" << endl;
	cin >> x1 >> x2;
	swapVals(&x1, &x2);
	cout << "x1 = " << x1 << " and x2 = " << x2 << endl;
	
	return 0;
}