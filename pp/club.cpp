#include "club.h"

Club::Club(std::string name){this->_name=name;}

std::string Club::name() {return _name;}
//std::string Club::email() {return _email;}
//std::string Club::phone() {return _phone;}
void Club::add_person(Person& person) {
    _available.push_back(&person);
}
int Club::num_person() {return _available.size();}
Person& Club::person(int index) {return *(_available[index]);}//yo chai bujina

