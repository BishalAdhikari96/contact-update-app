#ifndef __LOGIN_H
#define __LOGIN_H

#include <vector>
#include <string>
#include <gtkmm.h>
#include <iostream>
using namespace std;

class login:public Gtk::Window {
  public:
 login();
virtual ~login();
string customername;
bool val = false;

vector<string>_username;
vector<string>_password;
vector<string>_phonenumber;
protected:
Gtk::Label l_name,l_password;
Gtk::Entry e_name,e_password;
Gtk::Grid grid;
Gtk::Separator m_separator1;
Gtk::CheckButton checkbutton;
Gtk::Button logsin,signup;
 void on_login_click();
 void on_signup_click();
void toggle_checkbox();

  };

#endif

