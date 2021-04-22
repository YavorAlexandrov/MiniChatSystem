#include <iostream>
#include<fstream>
#include "DateTime.h"
#include"User.h"
#include"Database.h"
#include"System.h"
using namespace std;
void copyNextWord(char* dest, char* source);
int main()
{
    Database d(20);
    System s(d);

    s.getDatabase().loadUsersFromFile("users.vgdb");
   /* s.Register("Yavor", "bvww", "yavor@mail.com");
    for (int i = 0; i < s.getDatabase().getSize()-1; i++) {
        cout << s.getDatabase()[i].getUsername() << " " << s.getDatabase()[i].getPassword() << " "
            << s.getDatabase()[i].getEmail() << " " << s.getDatabase()[i].getID() << endl;
    }*/
    



    char command[16];

    while (1) {
        
        cin.getline(command, 16);
        if (strcmp(command, "register") == 0) {
            cout << "Enter a new username, password and an email:\n>";
            char buff[128];
            cin.getline(buff, 128);
            char* name = new char [32];
            copyNextWord(name, buff);
            char* pass = new char[32];
            copyNextWord(pass, buff);
            char* email = new char[32];
            copyNextWord(email, buff);
           
            bool success;
            s.Register(name, pass, email, success);
            if (success) {
                cout << "Registration successful!"<<endl;
            }

        }
        else if (strcmp(command, "login") == 0) {
            cout << "Enter username and password:\n>";
            char buff[128];
            cin.getline(buff, 128);
            char name[32];
            copyNextWord(name, buff);
            char pass[32];
            copyNextWord(pass, buff);
            
            int ind = s.login(name, pass);

            if (ind != -1) {
                cout << "Successful login! To message someone write 'message receiver yourMessage'.\n";
                while (true) {
                    char comm[32];
                    char n[32];
                    char b[512];
                    cin.getline(b, 512);
                    copyNextWord(comm, b);
                    copyNextWord(n, b);
                    if (strcmp(comm, "message") == 0) {
                        Message m(b, s.getDatabase()[ind], s.getDatabase()[s.getDatabase().findUserByUsername(n)]);
                        s.sendMessageTo(s.getDatabase()[ind], m.getReceiver(), m);
                    }
                    else if (strcmp(comm, "show") == 0 && strcmp(n, "chat") == 0) {

                    }
                    else if (strcmp(comm, "logout") == 0) {
                        cout << "Logging out...\n";
                        break;
                    }
                    else {
                        cout << "Invalid command!\n";
                    }
                }

            }
            else {
                cout << "Unsuccessful login!"<<endl;
            }
        }
        else if (strcmp(command, "forgotten password")==0) {

        }
        else if (strcmp(command, "exit") == 0) {
            cout << "Exiting..." << endl;
            break;
        }
        else {
            cout << "Invalid command!"<<endl;
        }
        //cin.ignore();
    }
    for (int i = 0; i < s.getDatabase().getSize() - 1; i++) {
        cout << s.getDatabase()[i].getUsername() << " " << s.getDatabase()[i].getPassword() << " "
            << s.getDatabase()[i].getEmail() << " " << s.getDatabase()[i].getID() << endl;
    }
    /*cout<<s.getDatabase().getSize();*/
    //Message m("I'm good as well! Thanks!", s.getDatabase()[1], s.getDatabase()[0]);
   // s.sendMessageTo(s.getDatabase()[1], s.getDatabase()[0], m);
    
   /* for (int i = 0; i < s.getDatabase().getSize(); i++) {
        cout << s.getDatabase()[i].getUsername() << " " << s.getDatabase()[i].getPassword() << " "
            << s.getDatabase()[i].getEmail() << " " << s.getDatabase()[i].getID() << endl;
    }*/
   // s.Register("Ico", "zxcv", "ico@mail.com");
    cout << endl;
   /* int currId = s.login("Yavor", "123");
    int size = s.getDatabase().getSize();
    User currUser;
    for (int i = 0; i < size; i++) {
        if (s.getDatabase()[i].getID() == currId) {
            currUser = s.getDatabase()[i];
        }
    }
    
    cout<<currUser.getEmail();*/

    //s.forgottenPassword("asd", "pesho@mail.com");


     
}

void copyNextWord(char* dest, char* source) {
    int i = 0;
    while (source[i] != ' ') {
        if (source[i] == '\n') {
            break;
        }
        dest[i] = source[i];
        i++;
        
    }
    
    dest[i] = '\0';
    int j = strlen(source);
    int k = 0;
    i++;
    while ( i < j ) {
        source[k] = source[i];
        i++; 
        k++;
    }
    source[k] = '\0';
    
}