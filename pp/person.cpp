#include "person.h"

// Constructors / Destructors
Person::Person(std::string name, std::string email, std::string number)
    {this->_name=name;this->_email=email;this->_age=number;}

Person::~Person() { }

// Getters
std::string Person::name() const {return _name;}
std::string Person::email() const {return _email;}
std::string Person::age() const {return _age;}

