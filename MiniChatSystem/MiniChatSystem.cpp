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
    cout<<s.getDatabase().getSize();

    
    s.Register("Penka", "098765", "penka@mail.com");
   


     
}

