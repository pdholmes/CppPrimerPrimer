// Exercise 5.9 on p. 183

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
		if (ch == 'a')
			++aCnt;
		if (ch == 'e')
			++eCnt;
		if (ch == 'i')
			++iCnt;
		if (ch == 'o')
			++oCnt;
		if (ch == 'u')
			++uCnt;
	}

	cout << endl;
	cout << "Number of a's: \t" << aCnt << endl;
	cout << "Number of e's: \t" << eCnt << endl;
	cout << "Number of i's: \t" << iCnt << endl;
	cout << "Number of o's: \t" << oCnt << endl;
	cout << "Number of u's: \t" << uCnt << endl;

	return 0;
}