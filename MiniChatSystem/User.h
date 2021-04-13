#pragma once
#include"DateTime.h"
class User {
	char* username;
	char* pasword;
	char* email;
	int id;
	DateTime createdAt;
	DateTime updatedAt;
	
public:
	User();
	User(char* username, char* password, char* email); 
	void serialize();

};
