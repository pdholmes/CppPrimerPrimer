/* Exercise 6.4 on p. 205 */
// oops I guess I did this one early:
#include "Chapter6.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
	int x = 0;
	cout << "Type a number!" << endl;
	cin >> x;
	cout << x << "! = " << getFact(x) << endl;
	return 0;
}