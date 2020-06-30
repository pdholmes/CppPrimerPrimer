/* Exercise 6.12 on p. 212 */
// rewrite exercise 6.10 to use references... which one
// do you think is easier?
// I think this one is easier because you can just pass 
// the actual ints as references, rather than their addresses
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void swapVals(int& r1, int& r2) {
	int tmp = r1;
	r1 = r2;
	r2 = tmp;
}

int main(int argc, char const *argv[])
{
	int x1 = 0, x2 = 0;
	cout << "Type two numbers and we'll swap the value!" << endl;
	cin >> x1 >> x2;
	swapVals(x1, x2);
	cout << "x1 = " << x1 << " and x2 = " << x2 << endl;
	
	return 0;
}