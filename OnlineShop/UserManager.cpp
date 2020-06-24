#include "UserManager.h"

auto UserManager::find(const std::string& name) {

	for (std::vector<User*>::iterator iter = users.begin(); iter != users.end(); iter++) {

		if ((*iter)->checkName(name)) return iter;
	}

	return users.end();
}

Message UserManager::signUp(User& user) {

	Message msg;
	if (std::find(users.begin(), users.end(), &user) != users.end()) return msg.error("User already exists!");

	users.push_back(&user);
	return msg.success();
}

Message UserManager::logIn(const std::string& name, const std::string& password) {

	Message msg;
	
	auto iter = find(name);

	if (!validateUser(iter, password)) return msg.error("Wrong username or password!");

	loggedInUsers.push_back(*iter);
	return msg.success();
}

Message UserManager::logOut(const User& user) {

	Message msg;
	auto iter = std::find(users.begin(), users.end(), &user);

	if (iter == users.end()) return msg.error("User is not logged in!");

	loggedInUsers.erase(iter);

	return msg.success();
}

std::vector<User*>::iterator UserManager::getUser(const User& user) {

	return std::find(loggedInUsers.begin(), loggedInUsers.end(), &user);
}

Message UserManager::changePassword(const User& user, const std::string& password, const std::string& token) {

	auto iter = std::find(users.begin(), users.end(), &user);
	return (*iter)->changePassword(password, token);
}

bool UserManager::validateUser(std::vector<User*>::const_iterator iter, const std::string& password) {

	if (iter != users.end() && (*iter)->checkPassword(password)) return 1;

	return 0;
}