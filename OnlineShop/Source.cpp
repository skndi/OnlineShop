#include "Shop.h"

int main() {

	Shop shop;

	Customer cust("Georgi", "123", "asd", 1000);
	Administrator admin("Ivan", "321", "dsa");

	Item item1("Pechka", 20);
	Item item2("Peralnq", 30);

	shop.signUp(cust);
	shop.signUp(admin);
	shop.logIn("Georgi", "123");
	shop.logIn("Ivan", "321");

	shop.addItemToInventory(item1, 30);
	shop.addItemToInventory(item2, 50);

	cust.addToCart(item1, 15);
	
	shop.processOrder(cust);

	std::cout << shop.getStockOfItem(item1);
	return 0;
}