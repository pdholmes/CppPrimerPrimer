/*
Exercise 6.30 on p. 228
Compile the version of str_subrange as presented on page 223 to see what
your compiler does with the indicated errors.
*/

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

bool str_subrange(const string &str1, const string &str2) {
	if (str1.size() == str2.size())
		return str1 == str2;

	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

	for (decltype(size) i = 0; i!= size; ++ i){
		if (str1[i] != str2[i])
			return;
	}
}

int main(int argc, char const *argv[])
{
	string s1 = "Wassup";
	string s2 = "sup";
	bool tf = str_subrange(s1, s2);
}