#include "Item.h"

Item::Item(const std::string& name, const int& price) {

	this->name = name;
	this->price = price;
	
}

Item::Item(const Item& item) {

	this->name = item.name;
	this->price = item.price;

}

Item::Item(){

	price = 0;
}

int Item::getPrice() const{

	return price;
}

void Item::changePrice(const int& price) {

	this->price = price;
}

std::string Item::getName() const {

	return name;
}

bool operator ==(const Item& item1, const Item& item2) {

	if (item1.name == item2.name) return 1;

	return 0;
}

Item::~Item() {

}