#include "Administrator.h"

Administrator::Administrator() { userType = User::type::Administrator; }

Administrator::Administrator(const std::string& name, const std::string& password, const std::string& token) : User(name, password, token) {

	userType = User::type::Administrator;
}

User::type Administrator::getType() const{

	return userType;
}

bool operator ==(const Administrator& admin1, const Administrator& admin2) {

	if (admin1.getName() == admin2.getName()) return 1;

	return 0;
}