/* 
Exercise 5.21 on p. 192
Revise Exercise 5.20 so that it only looks for duplicated words that
start with an uppercase letter.
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
	string word;
	string prev_word;
	string msg = "No word was repeated!";

	cout << "Type words then hit enter!" << endl;

	while (cin >> word) {
		if (!isupper(word[0])){
			continue;
		}
		if (word == prev_word) {
			msg = word + " was repeated!";
			break;
		}
		prev_word = word;
	}

	cout << msg << endl;
	return 0;
}