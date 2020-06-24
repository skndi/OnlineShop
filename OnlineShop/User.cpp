#include "User.h"

User::User(const std::string& name, const std::string& password, const std::string& token) {

	this->name = name;
	this->password = password;
	this->token = token;
}

std::string User::getName() const {

	return name;
}

bool User::checkPassword(const std::string& password) const{

	if (this->password == password) return 1;

	return 0;
}

bool User::checkName(const std::string& name) const{

	if (this->name == name) return 1;

	return 0;
}

Message User::changePassword(const std::string& password, const std::string& token) {

	Message msg;

	if (token == this->token) {

		this->password = password;
		return msg.success();
	}

	
	return msg.error("Wrong token!");
}