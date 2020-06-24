#include "Customer.h"

Customer::Customer() {
	cash = 0;
	userType = User::type::Customer;
}

Customer::Customer(const std::string& name, const std::string& password, const std::string& token, const int& cash) : User(name, password, token) {

	this->cash = cash;
	userType = User::type::Customer;
}

const Cart& Customer::getCart() {

	return cart;
}

Message Customer::addToCart(const Item& item, const int& quantity) {

	Message msg;

	if (quantity <= 0) {

		return msg.error("Invalid quantity!");
	}

	return cart.addItem(item, quantity);
}

Message Customer::takeOutItem(const Item& item, const int& quantity) {

	return cart.takeOutItem(item, quantity);
}

std::pair<Item, int> Customer::getItemFromCart(const Item& item) {

	auto iter = cart.getItem(item);

	if (iter == cart.getItems().end()) return std::make_pair(item, 0);
	else return std::make_pair(iter->first, iter->second);
}

int Customer::costOfProductsInCart() const {

	return cart.costOfProducts();
}

Message Customer::clearCart() {

	return cart.clear();
}

bool Customer::checkFunds(const int& total) const{

	return ((cash - total) >= 0) ? 1 : 0;
}

User::type Customer::getType() const{

	return userType;
}

const Cart& Customer::getCart() const {

	return cart;
}

Message Customer::charge(const int& amount) {

	Message msg;
	if (!checkFunds(amount)) return msg.error("Not enough balance!");

	cash -= amount;
	return msg.success();
}

bool operator ==(const Customer& cust1, const Customer& cust2) {

	if (cust1.getName() == cust2.getName()) return 1;

	return 0;
}