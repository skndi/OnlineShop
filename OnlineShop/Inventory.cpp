#include "Inventory.h"

Message Inventory::changePrice(Item& item, const int& price) {

	Message msg;

	auto iter = getItems().find(item);

	if (iter == getItems().end()) {

		return msg.error("Item doesn't exist!");
	}
	std::pair<Item, int> temp = std::make_pair(Item(iter->first.getName(), price), iter->second);

	getItems().erase(iter);
	getItems().insert(temp);

	return msg.success();
}

Message Inventory::changeStock(Item& item, const int& quantity) {

	Message msg;
	auto iter = getItems().find(item);

	if (iter == getItems().end()) {

		return msg.error("Item doesn't exist!");
	}

	iter->second = quantity;
	return msg.success();
}

Message Inventory::takeOutItem(const Item& item, const int& quantity) {

	return takeOut(item, quantity);
}