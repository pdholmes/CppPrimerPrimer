// Exercise 5.14 on p. 185

#include <vector>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
	vector<string> all_words;
	vector<int> repetitions;
	string prev_word = "";
	string word;
	int wordCnt = 1;

	cin >> prev_word;

	while (cin >> word) {
		if (word != prev_word) {
			all_words.push_back(prev_word);
			repetitions.push_back(wordCnt);
			wordCnt = 1;
			prev_word = word;
		}
		else {
			++wordCnt;
		}
	}

	all_words.push_back(prev_word);
	repetitions.push_back(wordCnt);

	cout << "Detected the following words: " << endl;

	auto rep_beg = repetitions.begin();
	for (auto beg = all_words.begin(); beg != all_words.end(); ++beg) {
		cout << *beg << "\t" << *rep_beg << endl;
		++rep_beg;
	}

	return 0;
}