#pragma once
#include <string>
#include <iostream>
#include "Message.h"

class User
{
private:
	std::string name;
	std::string password;
	std::string token;

protected:
	enum class type{Administrator, Customer};

public:
	User() {  };

	User(const std::string&, const std::string&, const std::string&);

	std::string getName() const;

	virtual type getType() const = 0;

	bool checkPassword(const std::string&) const;
	bool checkName(const std::string&) const;

	Message changePassword(const std::string& password, const std::string& token);
};

