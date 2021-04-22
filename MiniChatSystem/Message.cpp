#pragma warning(disable : 4996)
#include "Message.h"
#include <iostream>
using namespace std;

Message::Message() {
	Message(nullptr, User(), User());
}

Message::Message(const char* content, const User& sentBy, const User& receiver) {
	setContent(content);
	setSentBy(sentBy);
	setReceiver(receiver);
	DateTime tm;
	setDateTime(tm);
}

void Message::setContent(const char* content)
{
	delete[] this->content;
	this->content = new char[strlen(content)+1];
	strcpy(this->content, content);
}


void Message::setSentBy(const User& sentBy)
{
	this->sentBy = sentBy;
}


void Message::setReceiver(const User& receiver)
{
	this->receiver = receiver;
}

void Message::setDateTime(const DateTime& tm) {
	this->createdAt = tm;
}

const char* Message::getContent() {
	return this->content;
}

void Message::print() {
	cout << content<<endl;
}

const DateTime& Message::getTm() {
	return this->createdAt;
}