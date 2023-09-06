#include <bits/stdc++.h>

#include "user.h"
#include "book.h"
#include "Admin.h"
#include "library.h"
#include "login.h"
#include "checkout.h"

using namespace std;

int main()
{
    library l; //library object
    checkout ch; //checkout object
    open: // opening label
    cout<<"Click 1 to login : "<<endl;
    cout<<"Click 0 to exit : "<<endl;
    string option; cin>>option;
    if(option == "0"){
     cout<<"Bye Bye";
     return 0;
    }

    else if(option == "1") goto login;
    else{
      cerr<<"This option not available"<<endl;
      goto open; // return to the main menu
    }
//----------------------------------- Login Form -------------------------------------------

     login:
     cout<<"Enter your user name :"<<endl;
     cout<<"Enter your password :"<<endl;
     string u_name,pass;
     cin.ignore();
     getline(cin , u_name);
     getline(cin , pass);
     login lg(u_name , pass);

//--------------------------------- Exist User Case -----------------------------------------
     if(lg.validUser()){
//---------------------------------  Admin Section ------------------------------------------

      if(lg.userState() == "admin"){
       cout<<"Hello admin ' "<<u_name<<" '"<<endl;
       Admin a;
       Ad:
       cout<<"Press 1 to add book : "<<endl;
       cout<<"Press 2 to delete book : "<<endl;
       cout<<"Press 3 to show all books : "<<endl;
       cout<<"Press 4 to go back : "<<endl;
       int opinion; cin>>opinion;
       switch(opinion){
        case 1:{

           string b_name; string authorName; string id;

           cout<<"Enter Book Name : "<<endl;
           cin.ignore();
           getline(cin,b_name);
           cout<<"Enter Author Name : "<<endl;

           getline(cin,authorName);
           cout<<"Enter Book Id : "<<endl;

           getline(cin,id);
           book b1(b_name , authorName , id);
            if(a.addBook(b1 , &l)){
             cout<<"Added Successfully"<<endl;
            }
            else{
              cout<<"This Book Already Added"<<endl;
            }
            goto Ad;
           break;
       }
       case 2:{
        cout<<"Enter Book id : "<<endl;
        string id;
        cin>>id;
        if(a.deleteBook(&l , id)){
          cout<<"Deleted Successfully"<<endl;
        }
        else{
           cout<<"Wrong book id"<<endl;
        }
        goto Ad;
        break;
       }
       case 3:{
        l.showAllbooks();
        goto Ad;
        break;
       }
       case 4:{
        goto login;
       }
      }
     }
//--------------------------------- User Section ------------------------------------------

     else if(lg.userState() == "user"){

      user u(u_name , pass);
      u.setId(lg.userId());
      cout<<"Welcome ' "<<u_name<<" '"<<endl;

      User: // user label

       cout<<"Click 1 to show All books : "<<endl;
       cout<<"Click 2 to Search for a book : "<<endl;
       cout<<"Click 3 to Checkout book : "<<endl;
       cout<<"Click 4 to show your checkouts : "<<endl;
       cout<<"Click 5 to Return book : "<<endl;
       cout<<"Click 6 to go back : "<<endl;
       int userOption;
       cin>>userOption;
       switch(userOption){

        case 1:{
         l.showAllbooks();
         goto User;
         break;
        }

        case 2:{
         cout<<"Enter Book Name : "<<endl;
         cin.ignore();
         string search_query;
         getline(cin , search_query);
         l.searchBook(search_query);
         goto User;
         break;
        }

        case 3:{
         cout<<"Enter book id :"<<endl;
         cin.ignore();
         string bookId;
         cin>>bookId;
         if(l.validBook(bookId)){ // check if this book exist or not
          if(ch.addChechout(u.getId() , bookId))
             cout<<"Operation done successfully"<<endl;
          else
             cout<<"You are already checked out this book"<<endl;
         }
         else{
           cout<<"Wrong Book ID !"<<endl;
         }
         goto User;
         break;
        }

        case 4:{

         ch.showCheckouts(u.getId());
         goto User;
         break;
        }

        case 5:{
         cout<<"Enter Book ID : "<<endl;
         cin.ignore();
         string bookId;
         cin>>bookId;
         if(ch.returnBook(u.getId() , bookId)){
           cout<<"Book returned successfully"<<endl;
         }
         else{
          cout<<"This book is not in your checkouts"<<endl;
         }
         goto User;
         break;
        }

        case 6:{
         goto login;
        }
      }
     }
//--------------------------------- Closing of Exist User Case-----------------------------
   }
//--------------------------------- Unavailable User Case ---------------------------------
     else{
      cout<<"Wrong username or password"<<endl;

      incorrcet_user:

      cout<<"Press 1 to continue : "<<endl;
      cout<<"Press 0 to go back : "<<endl;
      string option2; cin>>option2;
      try{
       if(option2 == "0")goto open;
       else if(option2 == "1") goto login;
       else throw option2;
      }
      catch(string e){
       cout<<"Invalid Option"<<endl;
       goto incorrcet_user;
      }
     }

    return 0;
}
