#pragma once
#include"User.h"
#include"DateTime.h"
class Message
{
	char* content;
	User sentBy;
	User receiver;
	DateTime createdAt;

	void serialize();
	void free();
	void copyFrom(const Message& other);
public:
	Message();
	Message(const char* content, const User& sentBy, const User& receiver);
	//the big 4
	Message(const Message& other);
	const Message& operator = (const Message& other);
	~Message();


	void print();
	void writeToFile();
	void loadFromFile();

	const char* getContent();
	const DateTime& getTm();
	User& getReceiver();
	
	void setContent(const char* content);
	void setSentBy(const User& sentBy);
	void setReceiver(const User& receiver);
	void setDateTime(const DateTime& tm);
};




