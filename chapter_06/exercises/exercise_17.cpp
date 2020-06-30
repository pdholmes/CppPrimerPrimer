/* Exercise 6.17 on p. 215 */
// Write a function to determine whether a string
// contains any captial letters. Write a function
// to change a string to all lowercase. Do the 
// parameters you used in these functions have the 
// same type? If so, why? if not, why not?

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool contains_capital(const string &s){
	bool contains_capital = false;
	for (char c : s) {
		if (isupper(c)) {
			contains_capital = true;
		}
	}
	return contains_capital;
}

void to_lowercase(string &s){
	for (char &c : s)
		c = tolower(c);

}

int main(int argc, char const *argv[])
{
	string word;
	cout << "Enter a word!" << endl;
	cin >> word;
	cout << "Does your word contain a capital? : " << contains_capital(word) << endl;
	to_lowercase(word);
	cout << "I made your word all lowercase... " << word << endl;
	return 0;
}

/* 
response: the parameters do not have the same type.
for contains_capital, a const string & makes more sense since we don't
want to alter the word. but for to_lowercase, it is more efficient
to just pass a reference to the function and change the object itself.
*/