#include "customer.h"

// Constructor / Destructor - note how delegation to base class works!
customer::customer(std::string name,std::string email,std::string age)
    : Person(name, email, age) { }
customer::~customer() { }


