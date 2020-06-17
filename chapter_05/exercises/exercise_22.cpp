/* 
Exercise 5.22 on p. 193
The last example in this section that jumped back to begin could be better
written using a loop. Rewrite the code to eliminate goto.
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
	// begin:
	// int sz = get_size();
	// if (sz <= 0) {
	// 	goto begin;
	// }

	int sz = -1
	while (sz <= 0)
		sz = get_size();

	return 0;
}