#ifndef UI_CONTROLLER_H
#define UI_CONTROLLER_H

#include "decaf_controller.h"
#include <gtkmm.h>
#include <iostream>

using namespace Gtk;
using namespace Glib;

class ModelColumns : public TreeModelColumnRecord {
public:
  ModelColumns() { add(m_col_text); }

  TreeModelColumn<ustring> m_col_text;
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

class SymbTableColumns : public TreeModelColumnRecord {
public:
  SymbTableColumns() {
    add(name);
    add(type);
    add(env);
  }

  TreeModelColumn<ustring> name;
  TreeModelColumn<ustring> type;
  TreeModelColumn<ustring> env;
};

class TypeColumns : public SymbTableColumns {
public:
  TypeColumns() : SymbTableColumns() { add(size); }

  TreeModelColumn<int> size;
};

class SymbolColumns : public TypeColumns {
public:
  SymbolColumns() : TypeColumns() { add(offset); }

  TreeModelColumn<int> offset;
};

class MethodColumns : public SymbTableColumns {
public:
  MethodColumns() : SymbTableColumns() { add(params); }

  TreeModelColumn<ustring> params;
};

class UIController {
private:
  RefPtr<Builder> builder;
  Window *main_window;
  Window *error_dialog;
  Notebook *main_notebook;
  FileChooserButton *file_chooser;
  Button *error_close_btn;
  TreeView *tree_view;
  TreeView *error_list;
  TreeView *symbol_table;
  TreeView *type_table;
  TreeView *method_table;

  ModelColumns m_columns;
  ErrorColumns e_columns;
  TypeColumns type_columns;
  SymbolColumns symb_columns;
  MethodColumns meth_columns;

public:
  UIController();
  ~UIController();
  Window *main();
  void parse_file();
  void close_error_window();
};

#endif