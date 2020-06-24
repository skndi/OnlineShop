#pragma once
#include <string>

class Item

{

private:

	int price;
	std::string name;
	
public:

	Item();

	Item(const Item&);

	Item(const std::string&, const int&);

	int getPrice() const;

	std::string getName() const;

	void changePrice(const int&);

	friend bool operator==(const Item&, const Item&);

	~Item();
};

class HashFunc {
public:
	size_t operator() (const Item& item) const{
		return std::hash<std::string>()(item.getName());
	}
};