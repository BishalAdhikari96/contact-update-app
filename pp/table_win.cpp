#include <iostream>
#include "table_win.h"

Table_win::Table_win()
: m_VBox(Gtk::ORIENTATION_VERTICAL),
  m_Button_Quit("Quit")
{
  set_title("Members");
  set_border_width(5);
  set_default_size(400, 200);

  add(m_VBox);

  //Add the TreeView, inside a ScrolledWindow, with the button underneath:
  m_ScrolledWindow.add(m_TreeView);

  //Only show the scrollbars when they are necessary:
  m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

  m_VBox.pack_start(m_ScrolledWindow);
  m_VBox.pack_start(m_ButtonBox, Gtk::PACK_SHRINK);

  m_ButtonBox.pack_start(m_Button_Quit, Gtk::PACK_SHRINK);
  m_ButtonBox.set_border_width(5);
  m_ButtonBox.set_layout(Gtk::BUTTONBOX_END);
  m_Button_Quit.signal_clicked().connect( sigc::mem_fun(*this,
              &Table_win::on_button_quit) );

  //Create the Tree model:
  m_refTreeModel = Gtk::ListStore::create(m_Columns);
  m_TreeView.set_model(m_refTreeModel);

  //Fill the TreeView's model
  Gtk::TreeModel::Row row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = 1;
  row[m_Columns.m_col_name] = "Bishal Adhikari";
  row[m_Columns.m_col_number] = 3182358625;
  row[m_Columns.m_col_email] = "bishaladhikari96@gmail.com";

  row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = 2;
  row[m_Columns.m_col_name] = "Pawan Khadka JI";
  row[m_Columns.m_col_number] = 1234567890;
  row[m_Columns.m_col_email] = "pawankhadkaji@gmail.com";

  row = *(m_refTreeModel->append());
  row[m_Columns.m_col_id] = 3;
  row[m_Columns.m_col_name] = "Nirakar Nepal ko Don";
  row[m_Columns.m_col_number] = 9876543210;
  row[m_Columns.m_col_email] = "nirakardon@gmail.com";

  //Add the TreeView's view columns:
  //This number will be shown with the default numeric formatting.
  m_TreeView.append_column("ID", m_Columns.m_col_id);
  m_TreeView.append_column("Name", m_Columns.m_col_name);

  m_TreeView.append_column_numeric("Phone number", m_Columns.m_col_number,
          "%010d" /* 10 digits, using leading zeroes. */);

  m_TreeView.append_column("email", m_Columns.m_col_email);

  //Make all the columns reorderable:
  //This is not necessary, but it's nice to show the feature.
  //You can use TreeView::set_column_drag_function() to more
  //finely control column drag and drop.
  for(guint i = 0; i < 2; i++)
  {
    auto column = m_TreeView.get_column(i);
    column->set_reorderable();
  }

  show_all_children();
}

Table_win::~Table_win()
{
}

void Table_win::on_button_quit()
{
  hide();
}

