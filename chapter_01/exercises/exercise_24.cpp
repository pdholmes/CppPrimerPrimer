/*
Exercise 1.24 on p. 24
Test the previous program by giving multiple transactions representing
multiple ISBNs. The records for each ISBN should be grouped together.
*/

#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item total, item;
	if (std::cin >> total) {
		int n_transactions = 1;
		while (std::cin >> item) {
			if (total.isbn() == item.isbn()){
				total += item;
				++n_transactions;
			}
			else {
				std::cout << n_transactions << " total transactions for " << total.isbn() << std::endl;
				std::cout << total << std::endl;
				n_transactions = 1;
				total = item;
			}
		}
		std::cout << n_transactions << " total transactions for " << total.isbn() << std::endl;
		std::cout << total << std::endl;
	}
	return 0;
}