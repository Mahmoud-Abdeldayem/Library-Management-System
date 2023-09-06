#include<string>

#ifndef BOOK_H
#define BOOK_H

using namespace std;

class book
{

  private:
    string name;
    string author_name;
    string id;
  public:
    book(string , string , string);
    string getName();
    string getAuthorname();
    string getId();
};

#endif // BOOK_H
