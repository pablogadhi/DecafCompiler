#include "ui_controller.h"

UIController::UIController() {
  builder = Builder::create_from_file("UI.glade");

  builder->get_widget("main_window", main_window);
  builder->get_widget("file_chooser", file_chooser);
  builder->get_widget("tree_view", tree_view);
  builder->get_widget("error_window", error_dialog);
  builder->get_widget("error_list_view", error_list);
  builder->get_widget("error_close_btn", error_close_btn);

  main_window->set_default_size(800, 600);
  error_dialog->set_default_size(500, 400);

  file_chooser->signal_file_set().connect(
      sigc::mem_fun(*this, &UIController::parse_file));
  error_close_btn->signal_clicked().connect(
      sigc::mem_fun(*this, &UIController::close_error_window));

  // tree_view->append_column("index", m_columns.m_col_number);
  tree_view->append_column("Name", m_columns.m_col_text);

  error_list->append_column("Line", e_columns.line);
  error_list->append_column("Column", e_columns.col);
  error_list->append_column("Message", e_columns.msg);
}

UIController::~UIController() {}

Window *UIController::main() { return main_window; }

void add_parsing_level(RefPtr<TreeStore> &store, shared_ptr<DataNode> parent,
                       TreeModel::iterator &last_iter, ModelColumns &columns,
                       int &counter) {
  TreeModel::Row last_row = *last_iter;
  // last_row[columns.m_col_number] = counter;
  last_row[columns.m_col_text] = parent->get_text();
  counter++;

  for (auto &child : parent->get_children()) {
    TreeModel::iterator iter = store->append(last_row.children());
    add_parsing_level(store, child, iter, columns, counter);
  }
}

void UIController::parse_file() {
  auto file_name = file_chooser->get_filename();
  auto decaf = DecafController();
  decaf.load_file(file_name);

  if (decaf.get_errors().size() == 0) {
    RefPtr<TreeStore> refTreeStore = TreeStore::create(m_columns);

    TreeModel::iterator iter = refTreeStore->append();
    int row_counter = 0;
    add_parsing_level(refTreeStore, decaf.get_parse_root(), iter, m_columns,
                      row_counter);

    tree_view->set_model(refTreeStore);
    tree_view->expand_all();
  } else {
    RefPtr<TreeStore> data = TreeStore::create(e_columns);
    for (auto &e : decaf.get_errors()) {
      auto e_row = *(data->append());
      e_row[e_columns.line] = e.get_line();
      e_row[e_columns.col] = e.get_row();
      e_row[e_columns.msg] = e.get_msg();
    }

    error_list->set_model(data);
    error_dialog->show();
  }
}

void UIController::close_error_window() { error_dialog->close(); }