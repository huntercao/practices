// main.cpp
#include <string>
#include <iostream>
#include "Sales_item.h"

int main()
{
	std::cout << "implicity conversion." << std::endl;
	std::string null_book = "9-9999-99";

	Sales_item item;

	item.same_isbn(Sales_item(null_book));

	item.same_isbn(Sales_item(std::cin));

	return 0;
}
