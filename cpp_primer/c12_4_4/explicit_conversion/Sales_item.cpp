// Sales_item.cpp
#include <string>

#include "Sales_item.h"

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

double Sales_item::avg_price() const
{
	if(units_sold)
	{
		return revenue/units_sold;
	}
	else
	{
		return 0;
	}
}

//c14.2.1
ostream&
operator<<(ostream& out, const Sales_item& s)
{
	out << s.isbn << "\t" << s.units_sold << "\t"
	    << s.revenue << "\t" << s.avg_price();
	return out;
}

//c14.2.2
istream&
operator>>(istream& in, Sales_item& s)
{
	double price;
	in >> s.isbn >> s.units_sold >> price;

	if (in)
		s.revenue = s.units_sold * price;
	else
		s = Sales_item();
	return in;
}

//c14.3
Sales_item
operator+(const Sales_item& lhs, const Sales_item& rhs)
{
	Sales_item ret(lhs);
	ret += rhs;
	return ret;
}

//c14.4
Sales_item& Sales_item::operator+=(const Sales_item& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

Sales_item::Sales_item(std::istream &is)
{
	is >> *this;
}
