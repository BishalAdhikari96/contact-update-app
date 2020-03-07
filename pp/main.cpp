#include "login.h"
#include "mainwin.h"
#include <iostream>
#include <gtkmm.h>

using namespace std;



int main(int argc, char *argv[])
{
    Gtk::Main app(argc, argv);
    login l;
    Gtk::Main::run(l);
    if(l.val==true){ 
    Mainwin win(l.customername);
    Gtk::Main::run(win); }
    return 0;
}


