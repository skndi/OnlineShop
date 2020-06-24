#include "Cart.h"

Message Cart::addItem(const Item& item, const int& quantity) {

	Message msg;

	if (!checkQuantity(quantity)) { return msg.error("Invalid quantity"); }

	if (checkItemExistance(item)) {

		getItems().find(item)->second += quantity;
		return msg.success();
	}

	else msg = ItemOrganizer::addItem(item, quantity);
	return msg;
}

Message Cart::clear() {

	Message msg;

	while(getItems().size()) {

		auto iter = getItems().begin();
		getItems().erase(iter);
	}

	return msg.success();
}

Message Cart::takeOutItem(const Item& item, const int& quantity) {

	Message msg;

	msg = takeOut(item, quantity);
	if (getItems().find(item)->second == 0) removeItem(item);

	return msg;
}

int Cart::costOfProducts() const{

	int sum = 0;

	for (auto iter = getItems().begin(); iter != getItems().end(); iter++) {

		sum += iter->second * iter->first.getPrice();
	}

	return sum;
}