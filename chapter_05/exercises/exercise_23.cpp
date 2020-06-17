/* 
Exercise 5.23 on p. 198
Write a program that reads two integers from the standard input
and prints the result of dividing the first number by the second.
*/

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
	int i1 = 0;
	int i2 = 0;
	double result = 0;

	cout << "Type two integers! I will divide them :)" << endl;
	cin >> i1 >> i2;

	result = double(i1)/i2;
	cout << "Your result is: " << result << endl;
	return 0;
}