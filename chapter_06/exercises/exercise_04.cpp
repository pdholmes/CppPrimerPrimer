/* Exercise 6.4 on p. 205 */
// oops I guess I did this one early:
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