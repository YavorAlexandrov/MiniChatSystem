#include <iostream>
#include<fstream>
#include "DateTime.h"
#include"User.h"
#include"Database.h"
#include"System.h"
using namespace std;

int main()
{
    Database d(10);
    System s(d);

    s.getDatabase().loadUsersFromFile("users.vgdb");


    while (true) {

    }

    /*cout<<s.getDatabase().getSize();*/
    Message m("I'm good as well! Thanks!", s.getDatabase()[1], s.getDatabase()[0]);
    s.sendMessageTo(s.getDatabase()[1], s.getDatabase()[0], m);
    
    /*for (int i = 0; i < s.getDatabase().getSize(); i++) {
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

