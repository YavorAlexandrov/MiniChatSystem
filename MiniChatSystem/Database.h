#pragma once
#include"User.h"
#include<iostream>
#include<fstream>
class Database
{	
	User* users;
	int size;
	int capacity;
	

	void serialize();
	

	void free();
	void copyFrom(const Database& other);
public:
	Database();
	Database(int capacity);
	Database(const Database& other);
	const Database& operator = (const Database& other);
	~Database();

	int getSize() const;
	void setSize(int size);

	const int findUserByID(int id);
	const int findUserByEmailAddress(const char* email);
	const int findUserByUsername(const char* username);
	void loadUsersFromFile(const char* fileName);
	void saveUsersToFile(const User& user, const char* fileName);
	void addUser(const User& other);
	bool validateUser(const char* username);

	User& operator [](int index);
};

