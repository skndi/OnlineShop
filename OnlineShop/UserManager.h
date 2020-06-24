#pragma once
#include "Administrator.h"
#include "Customer.h"

class UserManager
{

private:
	std::vector<User*> users;
	std::vector<User*> loggedInUsers;

	auto find(const std::string& name);
	bool validateUser(std::vector<User*>::const_iterator, const std::string& password);

public:
	virtual Message signUp(User& user);

	virtual Message logIn(const std::string& name, const std::string& password);

	virtual std::vector<User*>::iterator getUser(const User& user);

	Message changePassword(const User& user, const std::string& password, const std::string& token);

	Message logOut(const User& user);
};

