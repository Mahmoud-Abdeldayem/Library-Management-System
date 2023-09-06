#include <string>
#include <vector>
#include "book.h"
#include "library.h"
//#include "checkout.h"

#ifndef USER_H
#define USER_H

using namespace std;

class user
{
   friend class library;
   private:
       string name;
       string password;
       string id;

   public:
    user(string , string); // passing name and password to constructor
    string getName();
    string getId();
    void setId(string);
    void showCheckouts();
};

#endif // USER_H
