// Exercise 5.11 on p. 183
/* 
Wow I am dumb... I learned a very important lesson today.
You should initialize your ints to be 0 if you want them to be 0.
They don't default initialize to 0.
That is all.
Took me 30 minutes to find that bug.
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	int aCnt = 0;
	int eCnt = 0;
	int iCnt = 0;
	int oCnt = 0;
	int uCnt = 0;
	int spaceCnt = 0;
	int tabCnt = 0;
	int lineCnt = 0;
	int totalCnt = 0;
	// cout << "Type something and we will count vowels!" << endl;

    string userInput;
    while (getline(cin, userInput))
    {
    	++lineCnt;
		for (auto ch : userInput) 
		{
			++totalCnt;
			// ch = tolower(ch);
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
				case ' ':
					++spaceCnt;
					break;
				case '\t':
					++tabCnt;
					break;
			}
		}
	}

	cout << endl;
	cout << "Number of a's: \t" << aCnt << endl;
	cout << "Number of e's: \t" << eCnt << endl;
	cout << "Number of i's: \t" << iCnt << endl;
	cout << "Number of o's: \t" << oCnt << endl;
	cout << "Number of u's: \t" << uCnt << endl;
	cout << "Number of spaces: \t" << spaceCnt << endl;
	cout << "Number of tabs: \t" << tabCnt << endl;
	cout << "Number of new lines: \t" << lineCnt << endl;


	return 0;
}