#pragma warning(disable : 4996)
#include"User.h"
#include <iostream>



User::User():username(nullptr), password(nullptr), email(nullptr), id(-1) {
}

User::User(const char* username, const char* password, const char* email, int id) {
	setUsername(username);
	setPassword(password);//must hash the password
	setEmail(email);
	setID(id);
	setCreatedAt();
	setUpdatedAt();
}
User::User(const User& other) {
	copyFrom(other);
}

User& User::operator =(const User& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

User::~User() {
	free();
}

void User::copyFrom(const User& other) {
	this->username = new char[strlen(other.username)+1];
	strcpy(this->username, other.username);

	this->password = new char[strlen(other.password)+1];
	strcpy(this->password, other.password);

	this->email = new char[strlen(other.email )+1];
	strcpy(this->email, other.email);

	this->id = other.id;

	this->createdAt = other.createdAt;

	this->updatedAt = other.updatedAt;

}

void User::free() {
	delete[] this->username;
	delete[] this->password;
	delete[] this->email;
}



void User::setUsername(const char* username)
{
	delete[] this->username;
	this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);
}

void User::setPassword(const char* password)
{
	delete[]this->password;
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
}


void User::setEmail(const char* email)
{
	delete[]this->email;
	this->email = new char[strlen(email) + 1];
	strcpy(this->email, email);
}


void User::setID(int id)
{
	this->id = id;
}

void User::setCreatedAt() {
	DateTime tm;
	this->createdAt = tm;
}

void User::setUpdatedAt() {
	DateTime tm;
	this->updatedAt = tm;
}

int User::getID() const{
	return this->id;
}

const char* User::getEmail() const{
	return this->email;
}

const char* User::getUsername() const{
	return this->username;
}

const char* User::getPassword() const {
	return this->password;
}