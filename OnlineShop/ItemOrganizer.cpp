#include "Inventory.h"

Message ItemOrganizer::addItem(const Item& item, const int& quantity) {
	
	Message msg;
	if (checkItemExistance(item)) return msg.error("Item already exists!");
	if(!checkQuantity(quantity)) return msg.error("Invalid quantity!");

	items.insert(std::make_pair(item, quantity));

	return msg.success();
}

bool ItemOrganizer::checkItemExistance(const Item& item) {

	if (items.find(item) == items.end()) return 0;
	return 1;
}

Message ItemOrganizer::removeItem(const Item& item) {

	Message msg;

	auto iter = items.find(item);

	if (iter == items.end()) {

		return msg.error("Item doesn't exist!");
	}

	items.erase(iter);

	return msg.success();
}

Message ItemOrganizer::takeOut(const Item& item, const int& quantity) {

	Message msg;
	auto iter = items.find(item);

	if (iter == items.end()) return msg.error("Item doesn't exist!");

	if (!checkQuantity(quantity, iter->second)) {

		return msg.error("Invalid quantity!");
	}

	iter->second -= quantity;
	return msg.success();
}

std::unordered_map<Item, int, HashFunc>& ItemOrganizer::getItems(){

	return items;
}

const std::unordered_map<Item, int, HashFunc>& ItemOrganizer::getItems() const{

	return items;
}

std::unordered_map<Item, int>::iterator ItemOrganizer::getItem(const Item& name){

	return items.find(name);
}

int ItemOrganizer::getStock(const Item& item) const{

	return items.at(item);
}

std::unordered_map<Item, int>::iterator ItemOrganizer::search(const std::string& name) {

	for (std::unordered_map<Item, int>::iterator iter = items.begin(); iter != items.end(); iter++) {

		if (iter->first.getName() == name) return iter;
	}

	return items.end();
}
