/* 
Exercise 5.24 on p. 198
Revise program in 5.23 to throw an exception if the second number is
zero. Test your program with a zero input to see what happens on your
system if you don't catch an exception.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::runtime_error;

int main(int argc, char const *argv[])
{
	int i1 = 0;
	int i2 = 0;
	double result = 0;

	cout << "Type two integers! I will divide them :)" << endl;
	cin >> i1 >> i2;

	if (i2 == 0)
		throw runtime_error("Attempted to divide by zero.");

	result = double(i1)/i2;
	cout << "Your result is: " << result << endl;
	return 0;
}