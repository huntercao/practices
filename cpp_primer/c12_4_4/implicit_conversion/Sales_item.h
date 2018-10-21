// Sales_item.h
#ifndef SALES_ITEM_H
#define SALES_ITEM_H

#include <string>

class Sales_item 
{
public: 
	Sales_item(const std::string &book = "") :
		isbn(book), units_sold(0), revenue(0.0) {}
	Sales_item(std::string &is);
	double avg_price() const;
	bool same_isbn(const Sales_item &rhs) const
		{ return isbn == rhs.isbn; }
	
	Sales_item(): units_sold(0), revenue(0.0) {    }
private:
	std::string isbn;
	unsigned units_sold;
	double revenue;
};

#endif
