#include <iostream>
#include <string>
#include "user.h"

using namespace std;

user::user(string Name , string Password):name(Name) , password(Password){
}

string user::getName(){
 return this->name;
}

string user::getId(){
 return this->id;
}

void user::setId(string Id){
 this->id = Id;
}
