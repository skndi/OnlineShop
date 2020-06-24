#include "Shop.h"

Message Shop::signUp(User& user) {

	return manager.signUp(user);
}

Message Shop::logIn(const std::string& name, const std::string& password) {

	return manager.logIn(name, password);
}

Message Shop::changePassword(const User& user, std::string password, std::string token) {

	return manager.changePassword(user, password, token);
}

Message Shop::logOut(const User& user) {

	return manager.logOut(user);
}

Message Shop::changePriceOfItem(Item& item, const int& price) {

	return inventory.changePrice(item, price);
}

Message Shop::changeStockOfItem(Item& item, const int& quantity) {

	return inventory.changeStock(item, quantity);
}

Message Shop::takeOutItem(const Item& item, const int& quantity) {

	return inventory.takeOutItem(item, quantity);
}

Message Shop::addItemToInventory(const Item& item, const int& quantity) {

	return inventory.addItem(item, quantity);
}

Message Shop::removeItemFromInventory(const Item& item) {

	return inventory.removeItem(item);
}

Message Shop::validateOrder(const Customer& customer) const{

	Message msg;

	auto iterEnd = customer.getCart().getItems().end();

	for (auto iter = customer.getCart().getItems().begin(); iter != iterEnd; iter++) {

		if (inventory.getItems().at(iter->first) - iter->second < 0) return msg.error("Not enough " + iter->first.getName() + " left in stock!");
	}

	return msg.success();
}

Message Shop::processOrder(Customer& customer)
{

	Message msg = validateOrder(customer);

	if (!msg.isSuccess()) return msg;

	msg = customer.charge(customer.costOfProductsInCart());

	if (!msg.isSuccess()) return msg;

	auto iterEnd = customer.getCart().getItems().end();

	for (auto iter = customer.getCart().getItems().begin(); iter != iterEnd; iter++) {

		inventory.takeOutItem(iter->first, iter->second);

	}

	return customer.clearCart();
}

int Shop::getStockOfItem(const Item& item) const {

	return inventory.getStock(item);
}