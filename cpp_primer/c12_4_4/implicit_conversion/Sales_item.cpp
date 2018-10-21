// Sales_item.cpp
#include <string>

#include "Sales_item.h"

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
