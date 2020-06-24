#include "Message.h"

Message::Message() {

	succ = false;
}

Message Message::success() {

	message = "Operation completed successfuly! \n";

	succ = true;

	return *this;
}

Message::Message(const Message& other) {

	this->message = other.message;
	this->succ = other.succ;

}

std::string Message::getMessage() const{

	return message;
}

Message Message::error(const std::string& errorType){

	message = "Error: ";
	message += errorType;

	succ = false;

	return *this;
}

bool Message::isSuccess() const{

	return succ;
}