#include<string>
#include "book.h"

using namespace std;

book::book(string Name , string authorName , string Id): name(Name) , author_name(authorName) , id(Id)
{
  //
}

string book::getName(){
 return this->name;
}

string book::getAuthorname(){
 return this->author_name;
}

string book::getId(){
 return this->id;
}
