#pragma once

#include "User.h"
#include "Cart.h"

class Customer : public User
{

private:

	int cash;
	type userType;
	Cart cart;
	bool checkFunds(const int& total) const;

public:
	Customer();

	Customer(const std::string& name, const std::string& password, const std::string& token, const int& cash = 0);

	Message addToCart(const Item& item, const int& quantity);
	
	Message takeOutItem(const Item& item, const int& quantity);

	std::pair<Item, int> getItemFromCart(const Item& item);

	const Cart& getCart() const;

	int costOfProductsInCart() const;

	Message charge(const int& amount);

	const Cart& getCart();

	type getType() const override;

	Message clearCart();

	friend bool operator ==(const Customer&, const Customer&);
};