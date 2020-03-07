#include "login.h"
#include <fstream>
#include <string>
#include <iostream>

login::login():checkbutton("Visible"){
        
    set_default_size(500, 400);
    set_title("Contact APP");
	
    Gtk::Box *m_box = Gtk::manage(new Gtk::VBox);
    add(*m_box);
    m_box->override_background_color(Gdk::RGBA("black"));

    Gtk::Box *h_box = Gtk::manage(new Gtk::HBox);
    Gtk::Box *user_h_box = Gtk::manage(new Gtk::HBox);
    Gtk::Box *pass_h_box = Gtk::manage(new Gtk::HBox);
    Gtk::Image* frng = Gtk::manage(new Gtk::Image{"clubmain.png"});
    
    m_box->pack_start(*frng);
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);    

    l_name.set_markup("<big>USERNAME</big>");
    l_name.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
//    grid.attach(l_name, 0, 1, 1, 1);
//    grid.attach(e_name, 1, 1, 2, 1);


    l_password.set_markup("<big>PASSWORD</big>");
    l_password.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);
    e_password.set_visibility(false);

   Gtk::Image* img = Gtk::manage(new Gtk::Image{"login.png"});
   logsin.set_image(*img);
   //logsin.set_label("LOGIN");
   logsin.override_background_color(Gdk::RGBA("green"));
   Gtk::Image* img1 = Gtk::manage(new Gtk::Image{"image.jfif"});
   signup.set_image(*img1);
   //signup.set_label("SIGNUP");
   signup.override_background_color(Gdk::RGBA("green"));

//   a_grid->override_background_color(Gdk::RGBA("black"));
//   a_grid->attach(logsin,0,0,2,1);
//   a_grid->attach(signup,2,0,1,1);
    h_box->pack_start(logsin);
    h_box->pack_start(signup);
   
 logsin.signal_clicked().connect(sigc::mem_fun(*this,&login::on_login_click));
 signup.signal_clicked().connect(sigc::mem_fun(*this,&login::on_signup_click));
 checkbutton.signal_toggled().connect(sigc::mem_fun(*this,&login::toggle_checkbox) );
  checkbutton.set_active(false);
  checkbutton.override_color (Gdk::RGBA("white"), Gtk::STATE_FLAG_NORMAL);

  user_h_box->pack_start(l_name);
  user_h_box->pack_start(e_name);
  pass_h_box->pack_start(l_password);
  pass_h_box->pack_start(e_password);
  m_box->pack_start(*user_h_box);
  m_box->pack_start(*pass_h_box);
  m_box->pack_start(checkbutton);
  m_box->pack_start(m_separator1);
  m_box->pack_start(*h_box);
  m_box->show_all();  

   };

login::~login() { }
void login::on_login_click()
{   
  //can create a dialog saying invalid if we have no on ein the list
  
  int i;// flag=true;
int x=0;

  std::ifstream opening;std::string naam,pass;int no;
  opening.open("Minidatabase1.txt");
  while(!opening.eof())
{
  opening>>naam>>pass;
  if(naam==e_name.get_text()&& pass==e_password.get_text())
 
{
login::customername=e_name.get_text();
login::val=true;
Gtk::MessageDialog dialog(*this,"SUCCESSFUL LOG IN",false,Gtk::MESSAGE_INFO);
dialog.run();
dialog.close();
close();
}
}


  if(login::val==false)
{
Gtk::MessageDialog dialog(*this,"INVALID ENTRY",false,Gtk::MESSAGE_INFO);
dialog.run();
dialog.close();
close();
}


/*if(login::val==false){
  for(i=0;i<login::_username.size();i++)
{
   if(login::_username[i]==e_name.get_text())
{
   if(login::_password[i]==e_password.get_text()){
login::customername=e_name.get_text();
login::val=true;


Gtk::MessageDialog dialog(*this,"SUCCESSFUL LOG IN",false,Gtk::MESSAGE_INFO);
dialog.run();
dialog.close();
close();
}
  
}

}}*/


}

void login::on_signup_click()
{
    Gtk::Dialog dialog{"SIGNUP PAGE", *this};
    Gtk::Grid grid;
    Gtk::Label l_name{"Username"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_phone{"Password"};
    Gtk::Entry e_phone;
    grid.attach(l_phone, 0, 1, 1, 1);
    grid.attach(e_phone, 1, 1, 2, 1);

    Gtk::Label l_email{"Email"};
    Gtk::Entry e_email;
    grid.attach(l_email, 0, 2, 1, 1);
    grid.attach(e_email, 1, 2, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Create account", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();
    // 
    while(dialog.run()) {
        int counter=0;
        std::ofstream creatingfile;
       creatingfile.open("Minidatabase1.txt",ios::app);
        if (e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}
        if (e_phone.get_text().size() == 0) {e_phone.set_text("*required*"); continue;}
        if (e_email.get_text().size() == 0) {e_email.set_text("*required*"); continue;}
       creatingfile << e_name.get_text()<<" "<<e_phone.get_text()<<std::endl;
       creatingfile.close();
        //shelter->add_client(*(new Client{e_name.get_text(), e_phone.get_text(), e_email.get_text()}));
        login::_username.push_back(e_name.get_text());
         login::_password.push_back(e_email.get_text());
          login::_phonenumber.push_back(e_phone.get_text());
          int s = login::_username.size();
     // std::ostream creatingfile;
      //creatingfile.open("Minidatabase1.txt");
      //for(counter=0;counter<s;counter++)
//{
  //   creatingfile <<_user <<"\n";}

     

    

     
        break;
    }


}

   
 void login::toggle_checkbox()
{
  e_password.set_visibility(checkbutton.get_active());
}

   
