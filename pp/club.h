#ifndef __CLUB_H
#define __CLUB_H
#include "person.h"
#include <vector>

class Club {
  public:
    Club(std::string name);//std::string email1,int phone;);
    std::string name();
   //std::string email();
   //std::int phone();
  

    void add_person(Person& person);
    int num_person();
    Person& person(int index); 


  //private:
    std::string _name;
 // std:: string _email1;
  //int _phone;
    std::vector<Person*> _available;
};

#endif

