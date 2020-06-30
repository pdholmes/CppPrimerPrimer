/* Exercise 6.7 on p. 206 */
// write a function that returns 0 when first called, and then generates numbers in sequence each time it is called again.
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int count_calls() {
	static int x = 0;
	return x++;
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i != 10; ++i)
		cout << count_calls() << endl;
}