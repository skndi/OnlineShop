#pragma once
#include "Inventory.h"
class Cart :
	public ItemOrganizer
{
public:
	Message addItem(const Item& item, const int& quantity);
	Message clear();
	Message takeOutItem(const Item& item, const int& quantity) override;
	int costOfProducts() const;
};

