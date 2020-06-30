/* Exercise 6.3 on p. 205 */
// write and test your own version of fact:
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int fact(int x) {
	int ret = 1;
	while (x > 1) {
		ret *= x--;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	int x = 0;
	cout << "Type a number!" << endl;
	cin >> x;
	cout << x << "! = " << fact(x) << endl;
	return 0;
}