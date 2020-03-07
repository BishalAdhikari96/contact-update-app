#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "club.h"

const std::string APP_TITLE{"Contact App"};
const std::string APP_NAME{"edu.uta.cse1325.mass.v0_1_0"};
const std::string VERSION{"0.1.0"};

class Mainwin : public Gtk::Window { 
    private:
     std::string _username;
    public:
        Mainwin(std::string username);
        virtual ~Mainwin();
    protected:
        void on_quit_click();              // Exit the application
         void on_save_click();
        void on_new_member_click();        // Create a new member
        void on_list_member_click();      // List all member
        void on_delete_click();    // Delete member
        void on_about_click();     //about 
        int tracker =0;
       //void on_new_client_click();        // Create a new client

       // void status(std::string s);        // Set the status message
	//Tree model columns:
  class ModelColumns : public Gtk::TreeModel::ColumnRecord
  {
  public:

    ModelColumns()
    { add(m_col_id); add(m_col_name); add(m_col_phone); add(m_col_email);}

    Gtk::TreeModelColumn<unsigned int> m_col_id;
    Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    Gtk::TreeModelColumn<Glib::ustring> m_col_phone;
    Gtk::TreeModelColumn<Glib::ustring> m_col_email;
  };


    private:
        Club *club;                  
        
};
#endif 

