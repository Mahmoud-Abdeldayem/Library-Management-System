#include <string>
#include <vector>
#include <utility>
#include <ctime>
#include "user.h"
#include "book.h"

#ifndef CHECKOUT_H
#define CHECKOUT_H

using namespace std;

class checkout
{
  private:
    vector< pair< string ,pair<string , string > > > checkouts; // pair( user_id , pair(book_id , date&time) )
  public:
    string makeTime();
    int addChechout(string , string);
    void showCheckouts(string);
    int returnBook(string , string);
};

#endif // CHECKOUT_H
