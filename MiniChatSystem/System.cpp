#include "System.h"

System::System(Database database) {
	this->database = database;
}

void System::Register(const char* username, const char* password, const char* email) {
	int id = database.getSize();
	
	User user(username, password, email, id);
	if(!database.validateUser(username)) {
		std::cout<<"Username is already taken!";
		return;
	}
	database.saveUsersToFile(user, "users.vgdb");
	database.addUser(user);
	database.setSize(++id);
}
int System::login(const char* username, const char* password) {
	for (int i = 0; i < database.getSize(); i++) {
		if (strcmp(database[i].getUsername(), username)==0) {
			if (strcmp(database[i].getPassword(), password) == 0) {
				return database[i].getID();
			}
			else {
				std::cout << "Wrong password!";
				return -1;
			}
		}
	}
	return -1;
}
void System::forgottenPassword(const char* newPassword, const char* email) {

}
void System::sendMessageTo(User user, Message message) {

}
void System::myMessagesWith(User user, int numberOfMessages) {

}

Database& System::getDatabase() {
	return database;
}


