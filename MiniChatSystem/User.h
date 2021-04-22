#pragma once
#include"DateTime.h"


class User {
	char* username;
	char* password;
	char* email;
	int id;
	DateTime createdAt;
	DateTime updatedAt;
	
	
	void setCreatedAt();
	void setUpdatedAt();
	
	void copyFrom(const User& other);
	void free();

public:
	User();
	User(const char* username, const char* password, const char* email, int id);
	User(char* username, char* password, char* email, int id);
	User(const User& other);
	User& operator =(const User& other);
	~User();
	void serialize();

	void setUsername(const char* username);
	void setPassword(const char* password);
	void setEmail(const char* email);
	void setID(int id);
	int getID() const;
	const char* getEmail() const;
	const char* getUsername() const;
	const char* getPassword() const;
	const DateTime& getCrAt() const;
	const DateTime& getUpAt() const;

	
};
