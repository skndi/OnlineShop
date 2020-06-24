#pragma once
#include <string>

class Message
{
private:
	std::string message;

	bool succ;

public:
	Message();

	Message(const Message& other);

	Message success();

	std::string getMessage() const;

	Message error(const std::string& message);

	bool isSuccess() const;
};

