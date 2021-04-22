#pragma once
#include"Database.h"
#include"Message.h"
class System
{
	Database database;
	char* getFileName(User& from, User& to);
public:
	System(Database database);

	void Register(const char* username, const char* password, const char* email);
	int login(const char* username, const char* password);
	void forgottenPassword(const char* newPassword, const char* email);
	void sendMessageTo(User& from, User& to, Message message);
	void myMessagesWith(User& from, User& to, int numberOfMessages);

	Database& getDatabase();
};

