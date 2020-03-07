#include "mainwin.h"
#include "customer.h"
#include <sstream>
#include <iostream>
#include<string>
#include<fstream>

Mainwin::Mainwin(std::string username) : club {new Club{"Let's check what's new?'"}} {
    this->_username=username;
    set_default_size(800, 600);
    set_title(APP_TITLE);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);
//    vbox->override_background_color(Gdk::RGBA("black"));

    



    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
 //     
   
   
    Gtk::Image* add_image = Gtk::manage(new Gtk::Image{"add.png"});
    Gtk::ToolButton *add = Gtk::manage(new Gtk::ToolButton(*add_image));
    add->set_tooltip_markup("ADD");
    add->signal_clicked().connect([this] {this->on_new_member_click();});
    toolbar->append(*add);

    Gtk::Image* save_image = Gtk::manage(new Gtk::Image{"save.png"});
    Gtk::ToolButton *save = Gtk::manage(new Gtk::ToolButton(*save_image));
    save->set_tooltip_markup("SAVE");
    save->signal_clicked().connect([this] {this->on_save_click();});
    toolbar->append(*save);

    Gtk::Image* list_image = Gtk::manage(new Gtk::Image{"list.png"});
    Gtk::ToolButton *list = Gtk::manage(new Gtk::ToolButton(*list_image));
    list->set_tooltip_markup("LIST");
    list->signal_clicked().connect([this] {this->on_list_member_click();});
    toolbar->append(*list);


    Gtk::Image* delete_image = Gtk::manage(new Gtk::Image{"delete.png"});
    Gtk::ToolButton *del = Gtk::manage(new Gtk::ToolButton(*delete_image));
    del->set_tooltip_markup("DELETE");
    del->signal_clicked().connect([this] {this->on_delete_click();});
    toolbar->append(*del);


    Gtk::Image* about_image = Gtk::manage(new Gtk::Image{"about.png"});
    Gtk::ToolButton *about = Gtk::manage(new Gtk::ToolButton(*about_image));
    about->set_tooltip_markup("ABOUT");
    about->signal_clicked().connect([this] {this->on_about_click();});
    toolbar->append(*about);


    Gtk::Image* logout_image = Gtk::manage(new Gtk::Image{"logout.png"});
    Gtk::ToolButton *logout = Gtk::manage(new Gtk::ToolButton(*logout_image));
    logout->set_tooltip_markup("LOGOUT");
    logout->signal_clicked().connect([this] {this->on_quit_click();});
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    toolbar->append(*logout);


    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);



     Gtk::Image* background_image = Gtk::manage(new Gtk::Image{"back1.jpg"});
     vbox->pack_start(*background_image);


 Gtk::LinkButton *linkbutton_google= new(Gtk::LinkButton);
linkbutton_google->set_label("Google");
linkbutton_google->set_uri("https://accounts.google.com/signin/v2/identifier?flowName=GlifWebSignIn&flowEntry=ServiceLogin");
vbox->pack_start(*linkbutton_google,Gtk::PACK_SHRINK, 0);
    vbox->show_all();
}

Mainwin::~Mainwin() { }



void Mainwin::on_quit_click() {    
close();
  
}

//instead of appending i should overwrite bro yo!!

    void Mainwin::on_save_click() {
    std::ofstream infile;int i;
   std::string filetobeopened= _username+".txt";
   //create a file with user name
    //infile.open("Minidatabase.txt",std::ios::app); //adds to the end of the file
     infile.open(filetobeopened);
    for(i=0;i<club->num_person();i++){
    infile << club->_available[i]->_name<<" "<<club->_available[i]->_email<<" " <<club->_available[i]->_age <<"\n";
    }
Gtk::MessageDialog d(*this,"SUCCESSFULLY SAVED",false,Gtk::MESSAGE_INFO);
d.run();

}

//this is the function where i read from file and create person object 

void Mainwin::on_new_member_click() {
    //read from filetobeopened
    //create a flag so that the file to be read 
    if (tracker==0){
   
    std::string filetobeopened= _username+".txt";
    std::ifstream infile;infile.open(filetobeopened);
    std::string customersname,customersphone,customersemail;
    if(infile.is_open())
  {  //Person* person;
    while(!infile.eof()){ 
        
    infile>> customersname>>customersemail>>customersphone;
   Person* person;
   person = new customer{ customersname,customersemail,customersphone};
       
        club->add_person(*person);
        tracker++;

        }   
  }}
    
    
    Gtk::Dialog dialog{ "Information", *this};

    Gtk::Grid grid;

    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_email{"email"};
   
    Gtk::Entry f_name;
    grid.attach(l_email, 0, 1, 1, 1);
    grid.attach(f_name, 1, 1, 2, 1);

  
Gtk::Label l_phone{"Phone"};
    Gtk::Entry e_phone;
    grid.attach(l_phone, 0, 2, 1, 1);
    grid.attach(e_phone, 1, 2, 2, 1);


    dialog.get_content_area()->add(grid);

    dialog.add_button("Add ", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();

    while(dialog.run()) {
      
        Person* person;
       
            person = new customer{ e_name.get_text(),f_name.get_text(),e_phone.get_text()};
       
        club->add_person(*person);
    
        break;
    }
}

void Mainwin::on_list_member_click() {
   //read from filetobeopened
    //int i;
    if(tracker==0){
    std::string filetobeopened= _username+".txt";
    std::ifstream infile;infile.open(filetobeopened);
    std::string customersname,customersphone,customersemail;
    if(infile.is_open())
  {  //Person* person;
    while(!infile.eof()){ 
        
    infile>> customersname>>customersemail>>customersphone;
   Person* person;
   person = new customer{ customersname,customersemail,customersphone};
       
        club->add_person(*person);tracker++;
       
        }
  }}
   Gtk::Dialog dialog{ "List of Members", *this};
   dialog.set_default_size(400, 400);
    ModelColumns m_Columns;
    //Gtk::Box m_VBox(Gtk::ORIENTATION_VERTICAL,120);
  Gtk::ScrolledWindow m_ScrolledWindow;
  Gtk::TreeView m_TreeView;
  Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
//Add the TreeView, inside a ScrolledWindow, with the button underneath:
  m_ScrolledWindow.add(m_TreeView);

  //Only show the scrollbars when they are necessary:
  m_ScrolledWindow.set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_NEVER);

  //Create the Tree model:
  m_refTreeModel = Gtk::ListStore::create(m_Columns);
  m_TreeView.set_model(m_refTreeModel);
//Fill the TreeView's model
  Gtk::TreeModel::Row row = *(m_refTreeModel->append());
  for(int i = 0; i<club->num_person();i++){
  row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = i+1;
  row[m_Columns.m_col_name] = club->_available[i]->_name;
  row[m_Columns.m_col_phone] = club->_available[i]->_age;
  row[m_Columns.m_col_email] = club->_available[i]->_email;
  }

//  row[m_Columns.m_col_id] = 1;
//  row[m_Columns.m_col_name] = "Bishal Adhikari";
//  row[m_Columns.m_col_age] = "31";
//  row[m_Columns.m_col_email] = "bishaladhikari96@gmail.com";
//  

  //Add the TreeView's view columns:
  m_TreeView.append_column("ID", m_Columns.m_col_id);
  m_TreeView.append_column("Name", m_Columns.m_col_name);

  m_TreeView.append_column("Phone", m_Columns.m_col_phone);

  m_TreeView.append_column("email", m_Columns.m_col_email);

  //m_VBox.pack_start(m_ScrolledWindow);

  dialog.get_content_area()->add(m_ScrolledWindow);

  dialog.add_button("Exit",1);

  dialog.show_all();
 
  dialog.run();
}
void Mainwin::on_delete_click(){
Gtk::Dialog dialog{ "CONTACT TO BE DELETED", *this};

    Gtk::Grid grid;

    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_email{"email"};
 
    Gtk::Entry f_name;
    grid.attach(l_email, 0, 1, 1, 1);
    grid.attach(f_name, 1, 1, 2, 1);

 
Gtk::Label l_phone{"Phone"};
    Gtk::Entry e_phone;
    grid.attach(l_phone, 0, 2, 1, 1);
    grid.attach(e_phone, 1, 2, 2, 1);


    dialog.get_content_area()->add(grid);

    dialog.add_button("DELETE ", 1);
    dialog.add_button("CANCEL", 0);

    dialog.show_all();
    dialog.run();


      
   int i=0;bool x=true;
   for(i=0;i<club->num_person();i++)
{

if((e_name.get_text()==club->_available[i]->_name )&& (f_name.get_text()==club->_available[i]->_email) && (e_phone.get_text()==club->_available[i]->_age))
{
   club->_available[i]->_name="---";
    club->_available[i]->_email="---";
     club->_available[i]->_age="---";
Gtk::MessageDialog de(*this,"NO CONTACT WITH SUCH DETAIL FOUND",false,Gtk::MESSAGE_INFO);
de.run();
x=false;


}

}

}
if(x==false){
Gtk::MessageDialog d(*this,"CONTACT DELETED",false,Gtk::MESSAGE_INFO);
d.run();}

}
void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog{};
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("Contact Management APP");
    auto logo = Gdk::Pixbuf::create_from_file("about.png");
    dialog.set_logo(logo);
    dialog.set_version(VERSION);
    dialog.set_copyright("Copyright 2017-2019");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"TEAM NAWAP \nCode Help: Professor Fadiah"};
    dialog.set_authors(authors);
std::vector< Glib::ustring > artists = {"TEAM NAWAP"
                                            };
    dialog.set_artists(artists);
    dialog.set_comments("WELCOME TO NAWAP CONTACT APP!!");
    dialog.run();
}



 

