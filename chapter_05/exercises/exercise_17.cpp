// Exercise 5.17 on p. 188
/* 
Given two vectors of ints, compare them to see if one is a
prefix of the other. If they are of uneven length, see if the
shorter one is a prefix of the longer one.
*/

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
	vector<int> x1 = {0, 1, 1, 2, 3, 5, 8};
	vector<int> x2 = {0, 1, 1, 2, 4};
	bool prefix = true;

	// auto sz1 = x1.size();
	// auto sz2 = x2.size();

	// for (decltype(x1.size()) ix = 0; (ix != sz1) && (ix != sz2); ++ix){
	// 	if (x1[ix] != x2[ix])
	// 		prefix = false;
	// }

	vector<int>* shortestVector = x1.size() < x2.size() ? &x1 : &x2;
	decltype(shortestVector->size()) i = 0;
	auto sz = shortestVector->size();

	for (/* init not required */; i != sz && x1[i] == x2[i]; ++i) {
		/* loop body not required */; 
	}

	cout << (i == sz ? "yup, it's a prefix!" : "nope, not a prefix!") << endl;
	return 0;
}