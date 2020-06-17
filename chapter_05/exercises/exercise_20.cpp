/* 
Exercise 5.20 on p. 191
Write a program to read a sequence of strings from the standard input
until either the same word occurs twice in succession or all the words
have been read. Use a while loop to read the text one word at a time.
Use the break statement to terminate the loop if a word occurs twice in
succession. Print the word if it occurs twice in succession, or else
print a message saying that no word was repeated.
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
		if (word == prev_word) {
			msg = word + " was repeated!";
			break;
		}
		prev_word = word;
	}

	cout << msg << endl;
	return 0;
}