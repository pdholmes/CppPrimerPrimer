/* Exercise 6.5 on p. 205 */
// write a function to return the absolute value of its argument:
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int abs(int x) {
	if (x < 0)
		x = -x;
	return x;
}

int main(int argc, char const *argv[])
{
	int x = 0;
	cout << "Type a number!" << endl;
	cin >> x;
	cout << "Abs value of " << x << " = " << abs(x) << endl;
	return 0;
}