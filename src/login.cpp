#include <string>
#include <map>
#include "login.h"

using namespace std;

login::login(string u_name , string u_password): username(u_name) , password(u_password) {

}

int login::validUser(){
  string u_name = this->username;
  string u_password = this->password;
  ifstream usersFile(this->usersfile);
  string name,password,State,u_id,lines;
  while(getline(usersFile , lines)){
    int cntr=0;
    string tmp;
    for(auto c:lines){
      if(c!='.')tmp+=c;
      if(c=='.' && cntr==0){
       name+=tmp;
       tmp = "";
       cntr++;
      }
      else if(c=='.' && cntr==1){
       password+=tmp;
       tmp = "";
       cntr++;
      }
      else if(c=='.' && cntr==2){
       State+=tmp;
       tmp = "";
       cntr++;
      }
      else if(c=='.' && cntr==3){
       u_id+=tmp;
       tmp = "";
      }
    }
    if(u_name == name && u_password == password){
        this->state = State;
        this->uId = u_id;
        return 1;
    }
    lines="";
    tmp="";
    name=""; password=""; State=""; u_id="";
  }
  return 0;
}

string login::userState(){
 return this->state;
}

string login::userId(){
 return this->uId;
}
