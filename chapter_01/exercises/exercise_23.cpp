/*
Exercise 1.23 on p. 24
Write a program that reads several transactions and counts how many
transactions occur for each ISBN.
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
				n_transactions = 1;
				total = item;
			}
		}
		std::cout << n_transactions << " total transactions for " << total.isbn() << std::endl;
	}
	return 0;
}