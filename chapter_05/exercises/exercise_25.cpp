/* 
Exercise 5.25 on p. 198
Revise program in 5.24 with a try catch statement
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
	while (cin >> i1 >> i2) {
		try {
			if (i2 == 0)
				throw runtime_error("Attempted to divide by zero.");
			result = double(i1)/i2;
			break;
		}
		catch (runtime_error err) {
			cout << err.what() << "\nTry again? Enter y or n" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break;
		}
	}

	cout << "Your result is: " << result << endl;
	return 0;
}