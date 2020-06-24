#pragma once
#include "User.h"

class Administrator : public User
{
private:

	type userType;

public:
	Administrator();

	Administrator(const std::string& name, const std::string& password, const std::string& token);

	type getType() const override;

	friend bool operator ==(const Administrator&, const Administrator&);
};

