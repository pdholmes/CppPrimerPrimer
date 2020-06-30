/* Exercise 6.11 on p. 212 */
// write and test your own version of reset that takes a reference
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void reset(int& r1) {
	r1 = 0;
}

int main(int argc, char const *argv[])
{
	int x1 = 0;;
	cout << "Type a number and I will make it zero!" << endl;
	cin >> x1;
	reset(x1);
	cout << "x1 = " << x1 << endl;
	
	return 0;
}