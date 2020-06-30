/*
Exercise 6.36 on p. 230
Write the declartio
*/

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype(odd) *arrPtr(int i) {
	return (i % 2) ? &odd : &even;
}

decltype(odd) &arrRef(int i) {
	return (i % 2) ? odd : even;
}

int main(int argc, char const *argv[])
{
    // Test with even numbers
    std::cout << arrRef(2) << std::endl;
    std::cout << arrRef(2)[2] << std::endl;
    // Test with odd numbers
    std::cout << arrRef(3) << std::endl;
    std::cout << arrRef(3)[2] << std::endl;
	
    return 0;
 }