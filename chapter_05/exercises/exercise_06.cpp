/* Exercise 5.6 on p. 178 */

#include <string>
#include <vector>
#include <iostream>

using std::vector;
using std::string;

int main(int argc, char const *argv[])
{
	const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
	int grade;
	string lettergrade;

	std::cout << "Type a number between 0 and 100!" << std::endl;
	std::cin >> grade;

	lettergrade = (grade < 60) ? scores[0] : scores[grade/10 - 5];
	lettergrade += (grade < 60 || grade == 100) ? "\0" :
								(grade % 10 > 7) ? "+" :
								(grade % 10 < 3) ? "-" : "\0}";

	std::cout << lettergrade << std::endl;

	return 0;
}