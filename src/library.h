#include <vector>
#include "book.h"
//#include "user.h"

#ifndef LIBRARY_H
#define LIBRARY_H

using namespace std;

class library
{
  friend class Admin;
  private:
      vector<book> boooks;
  public:
      void showAllbooks();
      void searchBook(string);
      int validBook(string);
};

#endif // LIBRARY_H
