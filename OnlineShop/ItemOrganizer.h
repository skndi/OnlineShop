#pragma once
#include "Item.h"
#include <map>
#include "Message.h"
#include <unordered_map>
#include <functional>

class ItemOrganizer
{

private:
	std::unordered_map<Item, int, HashFunc> items ;

protected:
	virtual Message takeOut(const Item& name, const int& quantity);
	bool checkItemExistance(const Item& item);
	bool checkQuantity(const int& quantity, int upperBound = INT_MAX) { return ( quantity > 0 && quantity <= upperBound) ? 1 : 0; };

public:
	virtual Message addItem(const Item& item, const int& quantity);

	virtual Message removeItem(const Item& item);

	virtual Message takeOutItem(const Item& item, const int& quantity) = 0;

	int getStock(const Item& item) const;

	std::unordered_map<Item, int, HashFunc>::iterator search(const std::string& name);

	std::unordered_map<Item, int>::iterator getItem(const Item& item);

	std::unordered_map<Item, int, HashFunc>& getItems();

	const std::unordered_map<Item, int, HashFunc>& getItems() const;

};