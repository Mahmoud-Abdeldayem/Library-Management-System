#include <iostream>
#include <string>
#include <fstream>

#ifndef LOGIN_H
#define LOGIN_H

using namespace std;

class login
{
  private:
      string username;
      string password;
      string state;
      string uId; // user id
      const string usersfile = "users.txt"; //users file

  public:
    login(string , string); // constructor
    int validUser(); // function check if the logged in user exist or not
    string userState(); // function return the state of the user(Admin or Normal user)
    string userId();
};

#endif // LOGIN_H
