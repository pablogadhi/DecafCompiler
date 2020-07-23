#ifndef UI_CONTROLLER_H
#define UI_CONTROLLER_H

#include "decaf_controller.h"
#include <gtkmm.h>
#include <iostream>

using namespace Gtk;
using namespace Glib;

class ModelColumns : public TreeModelColumnRecord {
public:
  ModelColumns() {
    add(m_col_text);
    add(m_col_number);
  }

  TreeModelColumn<ustring> m_col_text;
  TreeModelColumn<int> m_col_number;
};

class UIController {
private:
  RefPtr<Builder> builder;
  Window *main_window;
  FileChooserButton *file_chooser;
  TreeView *tree_view;

  ModelColumns m_columns;

public:
  UIController();
  ~UIController();
  Window *main();
  void parse_file();
};

#endif