#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <ctime>
#include <algorithm>
#include "checkout.h"
#include "user.h"
#include "book.h"

using namespace std;

string checkout::makeTime(){
 string timee;
 time_t now = time(0);
 tm *ltm = localtime(&now);
 int year = 1900 + ltm->tm_year;
 int month = ltm->tm_mon;
 int day = ltm->tm_mday;
 int hour = ltm->tm_hour;
 int mint = ltm->tm_min;
 int sec = ltm->tm_sec;
//----------year setting---------------------------
 while(year>0){
  timee+= (year%10)+'0';
  year/=10;
 }
 reverse(timee.begin() , timee.end());
 timee+='/';
//---------month setting----------------------------
 if(month<10){
  timee+='0';
  timee+= month+'0';
 }
 else{
 while(month>0){
   timee+= (month%10)+'0';
   month/=10;
  }
  reverse(timee.begin()+5 , timee.end());
 }
 timee+='/';
//---------day setting----------------------
 if(day<10){
  timee+='0';
  timee+= day+'0';
 }
 else{
 while(day>0){
   timee+= (day%10)+'0';
   day/=10;
  }
  reverse(timee.begin()+8 , timee.end());
 }
 timee+=' ';
//---------hour setting----------------------
 if(hour<10){
  timee+='0';
  timee+= hour+'0';
 }
 else{
  while(hour>0){
   timee+= (hour%10)+'0';
   hour/=10;
  }
  reverse(timee.begin()+11 , timee.end());
 }
 timee+=':';
//---------minute setting--------------------
 if(mint<10){
  timee+='0';
  timee+= mint+'0';
 }
 else{
  while(mint>0){
   timee+= (mint%10)+'0';
   mint/=10;
  }
  reverse(timee.begin()+14 , timee.end());
 }
 if(ltm->tm_hour<=12)
    timee+=" AM ";
 else
    timee+=" PM ";
 return timee;
}

int checkout::addChechout(string uid , string bid){ // user id , book id
 for(int i=0;i<this->checkouts.size();i++){
  if(this->checkouts[i].first == uid && this->checkouts[i].second.first == bid)
       return 0;
 }
 this->checkouts.push_back(make_pair(uid , make_pair(bid , this->makeTime())));
 return 1;
}

void checkout::showCheckouts(string uid){
 int cntr=0; // checkouts counter
 for(auto Checkout : this->checkouts){
  if(Checkout.first == uid){
    cout<<"Book id : "<<Checkout.second.first<<" | at : "<<Checkout.second.second<<endl;
    cntr++;
  }
 }
 if(cntr == 0)cout<<"You are haven't any checkouts"<<endl;
}

int checkout::returnBook(string userId , string bookId){
 for(int i=0 ; i<this->checkouts.size() ; i++){
  if(this->checkouts[i].first == userId && this->checkouts[i].second.first == bookId){
    this->checkouts.erase(this->checkouts.begin() + i);
    return 1;
  }
 }
 return 0;
}
