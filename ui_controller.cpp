#include "ui_controller.h"

UIController::UIController() {
  builder = Builder::create_from_file("UI.glade");

  builder->get_widget("main_window", main_window);
  builder->get_widget("file_chooser", file_chooser);
  builder->get_widget("tree_view", tree_view);
  builder->get_widget("error_window", error_dialog);
  builder->get_widget("error_list_view", error_list);
  builder->get_widget("error_close_btn", error_close_btn);
  builder->get_widget("main_notebook", main_notebook);
  builder->get_widget("symbol_table", symbol_table);
  builder->get_widget("type_table", type_table);
  builder->get_widget("method_table", method_table);
  builder->get_widget("code_view", code_view);
  builder->get_widget("compile_btn", compile_btn);
  builder->get_widget("intermediate_code_view", inter_code_view);

  main_window->set_default_size(800, 600);
  error_dialog->set_default_size(500, 400);

  file_chooser->signal_file_set().connect(
      sigc::mem_fun(*this, &UIController::load_file));
  error_close_btn->signal_clicked().connect(
      sigc::mem_fun(*this, &UIController::close_error_window));
  compile_btn->signal_clicked().connect(
      sigc::mem_fun(*this, &UIController::save_and_compile));

  // TODO Refactor this ugly code
  // tree_view->append_column("index", m_columns.m_col_number);
  tree_view->append_column("Name", m_columns.m_col_text);

  error_list->append_column("Line", e_columns.line);
  error_list->append_column("Column", e_columns.col);
  error_list->append_column("Message", e_columns.msg);

  symbol_table->append_column("Name", symb_columns.name);
  symbol_table->append_column("Type", symb_columns.type);
  symbol_table->append_column("Env", symb_columns.env);
  symbol_table->append_column("Size", symb_columns.size);
  symbol_table->append_column("Offset", symb_columns.offset);

  type_table->append_column("Name", type_columns.name);
  type_table->append_column("Type", type_columns.type);
  type_table->append_column("Env", type_columns.env);
  type_table->append_column("Size", type_columns.size);

  method_table->append_column("Name", meth_columns.name);
  method_table->append_column("Return Type", meth_columns.type);
  method_table->append_column("Father Env", meth_columns.env);
  method_table->append_column("Param Signature", meth_columns.params);
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

void UIController::load_file() {
  ifstream code_stream;
  file_name = file_chooser->get_filename();

  code_stream.open(file_name);
  stringstream temp_buffer;
  temp_buffer << code_stream.rdbuf();
  string content = temp_buffer.str();

  code_view->get_buffer()->set_text(content);
  parse_text(content);
}

void UIController::save_and_compile() {
  string content = code_view->get_buffer()->get_text();

  ofstream file_stream;
  file_stream.open(file_name);
  file_stream << content;
  file_stream.close();

  parse_text(content);
}

void UIController::parse_text(string &content) {
  auto decaf = DecafController();
  decaf.parse_text(content);

  if (decaf.get_errors().size() == 0) {
    // Populate syntax tree
    RefPtr<TreeStore> refTreeStore = TreeStore::create(m_columns);

    TreeModel::iterator iter = refTreeStore->append();
    int row_counter = 0;
    add_parsing_level(refTreeStore, decaf.get_parse_root(), iter, m_columns,
                      row_counter);

    tree_view->set_model(refTreeStore);
    tree_view->expand_all();

    // Populate symbol table
    auto table = decaf.symbol_table().first;
    auto envs = decaf.symbol_table().second;

    RefPtr<TreeStore> symbol_data = TreeStore::create(symb_columns);
    for (int i = 0; i < table.symbols().size(); i++) {
      auto s = table.symbols()[i];
      auto symb_row = *(symbol_data->append());
      symb_row[symb_columns.name] = s.name();
      symb_row[symb_columns.type] = s.type();
      symb_row[symb_columns.env] = envs[0][i];
      symb_row[symb_columns.size] = s.size();
      symb_row[symb_columns.offset] = s.offset();
    }

    symbol_table->set_model(symbol_data);

    // Populate type table
    RefPtr<TreeStore> type_data = TreeStore::create(type_columns);
    for (int i = 0; i < table.types().size(); i++) {
      auto t = table.types()[i];
      auto type_row = *(type_data->append());
      type_row[type_columns.name] = t.name();
      type_row[type_columns.type] = t.type();
      type_row[type_columns.env] = envs[1][i];
      type_row[type_columns.size] = t.size();
    }

    type_table->set_model(type_data);

    // Populate method table
    RefPtr<TreeStore> method_data = TreeStore::create(meth_columns);
    for (int i = 0; i < table.methods().size(); i++) {
      auto m = table.methods()[i];
      auto meth_row = *(method_data->append());
      meth_row[meth_columns.name] = m.name();
      meth_row[meth_columns.type] = m.type();
      meth_row[meth_columns.env] = envs[2][i];
      string params = "";
      for (auto &param : m.param_signature()) {
        params += param + ", ";
      }
      meth_row[meth_columns.params] = params;
    }

    method_table->set_model(method_data);

    // Set intermediate code
    inter_code_view->get_buffer()->set_text(decaf.intermediate_code());

    // Show a specific Tab
    main_notebook->set_current_page(3);

  } else {
    RefPtr<TreeStore> data = TreeStore::create(e_columns);
    for (auto &e : decaf.get_errors()) {
      auto e_row = *(data->append());
      e_row[e_columns.line] = e.get_line();
      e_row[e_columns.col] = e.get_pos();
      e_row[e_columns.msg] = e.get_msg();
    }

    error_list->set_model(data);
    error_dialog->show();
  }
}

void UIController::close_error_window() { error_dialog->close(); }