/*
Exercise 1.22 on p. 22
Write a program that reads several transactions for the same ISBN.
Write the sum of all the transactions that were read.
*/

#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item total, item;
	std::cin >> total;
	while (std::cin >> item) {
		if (total.isbn() == item.isbn()){
			total += item;
		}
		else {
			std::cerr << "Data must refer to the same ISBN" << std::endl;
			return -1;
		}
	}
	std::cout << total << std::endl;
	return 0;
}