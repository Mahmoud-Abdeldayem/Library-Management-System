#include <iostream>
#include <string>
#include "library.h"
#include "book.h"

using namespace std;

void library::showAllbooks(){
 if(this->boooks.size()>0){
 for(auto Book : this->boooks){
  cout<<"Book Name : "<<Book.getName()<<"  |  "<<"Author Name : "<<Book.getAuthorname()<<"  |  "<<"Book Id : "<<Book.getId()<<endl;
  }
 }
 else{
 cout<<"There Are No Books"<<endl;
 }
}

void library::searchBook(string Name){
 bool found = false;
 for(auto Book : this->boooks){
  if(Book.getName() == Name){
   found = true;
   cout<<"Book Name : "<<Book.getName()<<"  |  "<<"Author Name : "<<Book.getAuthorname()<<"  |  "<<"Book Id : "<<Book.getId()<<endl;
  }
 }
 if(found == false)
    cout<<"Not Found"<<endl;
}

int library::validBook(string bookId){
 for(auto Book : this->boooks){
  if(Book.getId() == bookId){
   return 1;
  }
 }
 return 0;
}
