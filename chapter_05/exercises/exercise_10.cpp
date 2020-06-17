// Exercise 5.10 on p. 183

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	char ch;
	int aCnt, eCnt, iCnt, oCnt, uCnt;
	cout << "Type something and we will count vowels!" << endl;
	while (cin >> ch) {
		ch = tolower(ch);
		switch (ch) {
			case 'a':
				++aCnt;
				break;
			case 'e':
				++eCnt;
				break;
			case 'i':
				++iCnt;
				break;
			case 'o':
				++oCnt;
				break;
			case 'u':
				++uCnt;
				break;
			default: {
				// deliberately empty
			}
		}
	}

	cout << endl;
	cout << "Number of a's: \t" << aCnt << endl;
	cout << "Number of e's: \t" << eCnt << endl;
	cout << "Number of i's: \t" << iCnt << endl;
	cout << "Number of o's: \t" << oCnt << endl;
	cout << "Number of u's: \t" << uCnt << endl;

	return 0;
}