#ifndef __cust_H
#define __cust_H

#include "person.h"

class customer : public Person {
  public:
    customer(std::string name,std:: string email, std::string age);
    virtual ~customer();
  
};

#endif
