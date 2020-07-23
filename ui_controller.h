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

class ErrorColumns : public TreeModelColumnRecord {
public:
  ErrorColumns() {
    add(line);
    add(col);
    add(msg);
  }

  TreeModelColumn<int> line;
  TreeModelColumn<int> col;
  TreeModelColumn<ustring> msg;
};

class UIController {
private:
  RefPtr<Builder> builder;
  Window *main_window;
  Window *error_dialog;
  FileChooserButton *file_chooser;
  Button *error_close_btn;
  TreeView *tree_view;
  TreeView *error_list;

  ModelColumns m_columns;
  ErrorColumns e_columns;

public:
  UIController();
  ~UIController();
  Window *main();
  void parse_file();
  void close_error_window();
};

#endif