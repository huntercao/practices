// main.cpp
#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item book;

	std::cout << "input book: \nisbn, units_sold, price;" << std::endl; 
	std::cin >> book;

	std::cout << "output: \nisbn, \tunits_sold, \trevenue, \tavg_price;" << std::endl; 
	std::cout << book << std::endl;

	Sales_item item1, item2;
	std::cout << "input item1 and item2" << std::endl;
	std::cin >> item1 >> item2;

	std::cout << "print sum of \"item1 + item2\"" << std::endl;
	std::cout << item1 + item2 << std::endl;

	return 0;
}
