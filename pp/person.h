#ifndef __person_H
#define __person_H

#include <ostream>



class Person {
  public:
    Person(std::string name, std::string email, std::string age);
    virtual ~Person();
   
    std::string name() const;
   std::string email() const;
   
   std::string age() const;
    

 

    std::string _name;
  std::string _email;
  std::string _age;
  
};

#endif

