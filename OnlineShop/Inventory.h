#pragma once
#include "ItemOrganizer.h"

class Inventory :
	public ItemOrganizer
{

public:
	Message changePrice(Item&, const int&);

	Message takeOutItem(const Item& name, const int& quantity) override;

	Message changeStock(Item&, const int&);
};

