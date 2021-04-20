#pragma once
#include"Database.h"
#include"Message.h"
class System
{
	Database database;

public:
	System(Database database);

	void Register(const char* username, const char* password, const char* email);
	int login(const char* username, const char* password);
	void forgottenPassword(const char* newPassword, const char* email);
	void sendMessageTo(User user, Message message);
	void myMessagesWith(User user, int numberOfMessages);

	Database& getDatabase();
};

