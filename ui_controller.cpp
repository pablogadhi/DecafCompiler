#include "ui_controller.h"

UIController::UIController() {
  builder = Builder::create_from_file("UI.glade");

  builder->get_widget("main_window", main_window);
  builder->get_widget("file_chooser", file_chooser);
  builder->get_widget("tree_view", tree_view);

  file_chooser->signal_file_set().connect(
      sigc::mem_fun(*this, &UIController::parse_file));

  tree_view->append_column("index", m_columns.m_col_number);
  tree_view->append_column("Name", m_columns.m_col_text);
}

UIController::~UIController() {}

Window *UIController::main() { return main_window; }

void add_parsing_level(RefPtr<TreeStore> &store, shared_ptr<DataNode> parent,
                       TreeModel::iterator &last_iter, ModelColumns &columns,
                       int &counter) {
  TreeModel::Row last_row = *last_iter;
  last_row[columns.m_col_number] = counter;
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

  RefPtr<TreeStore> refTreeStore = TreeStore::create(m_columns);

  TreeModel::iterator iter = refTreeStore->append();
  int row_counter = 0;
  add_parsing_level(refTreeStore, decaf.get_parse_root(), iter, m_columns,
                    row_counter);

  tree_view->set_model(refTreeStore);
  tree_view->expand_all();
}