#include"book.h"
#include "library.h"
#ifndef ADMIN_H
#define ADMIN_H


class Admin
{
  public:
       int addBook(book , library* l);
       int deleteBook(library* l , string Id);

};

#endif // ADMIN_H
