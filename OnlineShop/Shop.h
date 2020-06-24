#pragma once
#include "Administrator.h"
#include "Customer.h"
#include <vector>
#include <string>
#include "Item.h"
#include "Inventory.h"
#include "UserManager.h"

class Shop
{
private:
	Inventory inventory;
	UserManager manager;
	Message validateOrder(const Customer& customer) const;

public:
	Message signUp(User& user);

	Message logIn(const std::string& name, const std::string& password);

	Message changePassword(const User& user, std::string password, std::string token);

	Message logOut(const User& user);

	Message changePriceOfItem(Item& item, const int& price);

	Message takeOutItem(const Item& item, const int& quantity);

	Message changeStockOfItem(Item&, const int&);

	Message addItemToInventory(const Item& item, const int& quantity);

	Message removeItemFromInventory(const Item& name);

	Message processOrder(Customer& customer);

	int getStockOfItem(const Item& item) const;
};