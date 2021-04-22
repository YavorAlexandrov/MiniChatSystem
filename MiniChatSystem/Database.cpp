#include "Database.h"
#include<fstream>


void Database::free() {
	delete[] users;
}

void Database::copyFrom(const Database& other) {
	users = new User[other.capacity];
	for (int i = 0; i < other.getSize(); i++) {
		users[i] = User(other.users[i]);
	}

	capacity = other.capacity;
	size = other.size;
}


Database::Database(): users(nullptr), capacity(0) {
}
Database::Database(int capacity) {
	this->capacity = capacity;
	this->users = new User[capacity];
	this->size = 0;
	
}

Database::Database(const Database& other) {
	copyFrom(other);
}
const Database& Database::operator = (const Database& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Database::~Database() {
	free();
}

const int Database::findUserByID(int id) {
	for (int i = 0; i < size; i++) {
		if (users[i].getID() == id) {
			return i;
		}
	}
	return -1;
}
const int Database::findUserByEmailAddress(const char* email) {
	for (int i = 0; i < size; i++) {
		if (strcmp(users[i].getEmail(), email) == 0) {
			return i;
		}
	}

	return -1;
}
const int Database::findUserByUsername(const char* username) {
	for (int i = 0; i < size; i++) {
		if (strcmp(users[i].getUsername(), username) == 0) {
			return i;
		}
	}
	return -1;
}
void Database::loadUsersFromFile(const char* fileName) {
	std::ifstream f(fileName);
	int i = 0;
	while (f.good()) {
		
		char buff[128];
		f.get(buff, 128, ',');
		f.seekg(1, 1);
		users[i].setUsername(buff);
		f.get(buff, 128, ',');
		f.seekg(1, 1);
		users[i].setPassword(buff);
		f.get(buff, 128, ',');
		f.seekg(1, 1);
		users[i].setEmail(buff);
		f.get(buff, 128, ',');
		f.seekg(1, 1);
		int id = atoi(buff);
		users[i].setID(id);
		i++;
		size++;
		
	}
}
void Database::saveUsersToFile(const User& user, const char* fileName) {
	std::ofstream f(fileName, std::ios::app);
	if (!f.is_open())
	{
		std::cout << "Error while opening file!" << std::endl;
		return;
	}

	f << user.getUsername() << ',' << user.getPassword() << ',' << user.getEmail() << ',' << user.getID() << ',';
	/*user.getCrAt().printTime(f);
	f << ',';
	user.getUpAt().printTime(f);
	f << ',';*/

	f.close();
}


int Database::getSize() const{
	return size;
}

void Database::setSize(int size) {
	this->size = size;
}

bool Database::validateUser(const char* username) {
	for (int i = 0; i < size; i++) {
		if (strcmp(users[i].getUsername(), username) == 0) {
			return false;
		}
	}
	return true;
}

void Database::addUser(const User& other) {
	
	users[getSize()-1] = other;
}

User& Database::operator [](int index) {
	if (index >= capacity)
		throw "Invalid index";

	return users[index];
}