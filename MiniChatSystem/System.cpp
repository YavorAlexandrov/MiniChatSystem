#define _CRT_SECURE_NO_WARNINGS
#include "System.h"

System::System(Database database) {
	this->database = database;
}

void System::Register(const char* username, const char* password, const char* email, bool& successful) {
	int id = database.getSize();
	
	User user(username, password, email, id);
	if(!database.validateUser(username)) {
		std::cout<<"Username is already taken!";
		successful = false;
		return;
	}
	database.saveUsersToFile(user, "users.vgdb");
	database.addUser(user);
	database.setSize(++id);
	successful = true;
}
int System::login(const char* username, const char* password) {
	for (int i = 0; i < database.getSize()-1; i++) {
		if (strcmp(database[i].getUsername(), username)==0) {
			if (strcmp(database[i].getPassword(), password) == 0) {
				return database[i].getID()-1;
			}
			else {
				std::cout << "Wrong password!\n";
				return -1;
			} 
		}
	}
	return -1;
}

char* System::getFileName(User& from, User& to) {
	char buff[16] = { "" };
	char buff2[16] = { "" };

	if (from.getID() < to.getID()) {
		strcat(buff, _itoa(from.getID(), buff2, 10));
		strcat(buff, "_");
		strcat(buff, _itoa(to.getID(), buff2, 10));
		strcat(buff, ".dat");
	}
	else {
		strcat(buff, _itoa(to.getID(), buff2, 10));
		strcat(buff, "_");
		strcat(buff, _itoa(from.getID(), buff2, 10));
		strcat(buff, ".dat");
	}
	return buff;
}

void System::forgottenPassword(const char* newPassword, const char* email) {
	int emailLenght = strlen(email);
	int oldPassLenght{};
	for (int i = 0; i < database.getSize(); i++) {
		if (strcmp(database[i].getEmail(), email)==0) {
			oldPassLenght = strlen(database[i].getPassword());
			database[i].setPassword(newPassword);
			break;
		}
	}
	std::fstream f("users.vgdb", std::ios::in | std::ios::out | std::ios::beg);
	int indexToReplace{};
	while (f.good()) {
		char buff[64];
		f.get(buff, 64, ',');
		f.seekg(1, 1);
		if (strcmp(buff, email) == 0) {
			
			f.seekg(-(oldPassLenght + emailLenght + 2), std::ios::cur);
			indexToReplace =  f.tellg();
			break;
		}
	}
	std::cout << f.tellp()<<std::endl;
	f.seekp(indexToReplace, std::ios::beg);
	f << newPassword;
	char buff[2];
	f.seekg(indexToReplace, std::ios::beg);
	std::cout << f.tellg() << std::endl;
	f.get(buff, 2);
	while (strcmp(buff, ",")!=0) {
		f << buff;
		f.get(buff, 2);
	}
	std::cout << f.tellp() << std::endl;
	f.close();
	/*std::ofstream replacePass("users.vgdb", std::ios::ate);
	replacePass.seekp(--indexToReplace, std::ios::beg);
	replacePass << newPassword;
	std::cout << replacePass.tellp();*/
}
void System::sendMessageTo(User& from, User& to, Message message) {
	char buff[16];
	strcpy(buff, getFileName(from, to));

	
	std::ofstream out(buff, std::ios::app|std::ios::binary);
	out.write(from.getUsername(), strlen(from.getUsername())); 
	out.write(": ", 2);
	char temp[32] = { "" };
	strcpy(temp, message.getTm().getTimeAsString());
	out.write(temp, strlen(temp));
	out.write("\n", 1);
	out.write(message.getContent(), strlen(message.getContent()));
	out.write("\n", 1);
	
}
void System::myMessagesWith(User& from, User& to, int numberOfMessages) {
	char buff[16];
	strcpy(buff, getFileName(from, to));

	//std::ifstream(buff);

}

Database& System::getDatabase() {
	return database;
}


