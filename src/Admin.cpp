#include "Admin.h"
#include "book.h"
#include <vector>
#include <string>

using namespace std;

int Admin::addBook(book Book , library* Library){
 for(unsigned int i=0 ; i<Library->boooks.size() ; i++){
  if(Library->boooks[i].getId() == Book.getId())return 0;
 }
 Library->boooks.push_back(Book);
 return 1;
}

int Admin::deleteBook(library* Library , string Id){
 for(unsigned int i=0 ; i<Library->boooks.size() ;i++){
   if(Library->boooks[i].getId()==Id)
   {
     Library->boooks.erase(Library->boooks.begin()+i);
     return 1;
   }
 }
 return 0;
}
