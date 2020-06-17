/* Exercise 5.5 on p. 178 */

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

	if (grade < 60)
		lettergrade = scores[0];
	else {
		lettergrade = scores[grade/10 - 5];
		if (grade != 100) {
			if (grade % 10 > 7) {
				lettergrade += '+';
			}
			else if (grade % 10 < 3) {
				lettergrade += '-';
			}
		}
	}

	std::cout << lettergrade << std::endl;

	return 0;
}