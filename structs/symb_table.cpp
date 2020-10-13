#include "symb_table.h"
#include <algorithm>

TableRow::TableRow(string name, string type) : row_name(name), row_type(type) {}
TableRow::TableRow() {}
TableRow::~TableRow() {}
string TableRow::name() const { return row_name; }
string TableRow::type() { return row_type; }

Symbol::Symbol(string name, string type, int size, int offset)
    : TableRow(name, type), s_size(size), s_offset(offset) {}
Symbol::Symbol() : TableRow() {}
Symbol::~Symbol() {}
int Symbol::size() { return s_size; }
int Symbol::offset() { return s_offset; }

Type::Type(string name, string type, int size)
    : TableRow(name, type), t_size(size) {}
Type::Type() : TableRow() {}
Type::~Type() {}
int Type::size() { return t_size; }

Method::Method(string name, string type, vector<string> param_signature,
               string alias)
    : TableRow(name, type), m_param_signature(param_signature), m_alias(alias) {
}
Method::Method() : TableRow() {}
Method::~Method() {}
vector<string> Method::param_signature() const { return m_param_signature; }
void Method::set_alias(string alias) { m_alias = alias; }
string Method::alias() { return m_alias; }

SymbolTable::SymbolTable() {}
SymbolTable::SymbolTable(Method id) : t_id(id) {}
SymbolTable::SymbolTable(Method id, shared_ptr<SymbolTable> parent,
                         int b_offset)
    : t_id(id), t_parent(parent), base_offset(b_offset) {}
SymbolTable::~SymbolTable() {}

void SymbolTable::init_basic_types() {
  t_types.push_back(Type("char", "basic", 1));
  t_types.push_back(Type("boolean", "basic", 1));
  t_types.push_back(Type("int", "basic", 4));
}

Method &SymbolTable::id() { return t_id; }
string SymbolTable::name() { return t_id.name(); }
vector<Symbol> &SymbolTable::symbols() { return t_symbols; }
vector<Type> &SymbolTable::types() { return t_types; }
vector<Method> &SymbolTable::methods() { return t_methods; }

int SymbolTable::next_symbol_offset() {
  int offset = base_offset;
  if (!t_symbols.empty()) {
    auto last_symb = t_symbols.back();
    offset = last_symb.offset() + last_symb.size();
  }
  return offset;
}

void SymbolTable::add_symbol(string name, string type, int size,
                             function<void()> error_func) {
  if (!get_where<Symbol>(t_symbols,
                         [=](Symbol &s) { return s.name() == name; })) {
    auto new_symbol = Symbol(name, type, size, next_symbol_offset());
    t_symbols.push_back(new_symbol);

    Type type_ctr;
    shared_ptr<SymbolTable> found_in;
    auto self_ptr = shared_from_this();
    recursive_lookup<Type>(
        self_ptr, [&](shared_ptr<SymbolTable> table) { return table->types(); },
        [&](Type &t) { return t.name() == type; }, found_in, &type_ctr);
    if (type_ctr.type() == "struct") {
      auto struct_inst_table = make_shared<SymbolTable>(
          Method(name, type), self_ptr, new_symbol.offset());
      auto types_table =
          found_in->children()[Method(type_ctr.name(), "struct")];
      for (auto &memb : types_table->types()) {
        struct_inst_table->add_symbol(memb.name(), memb.type(), memb.size());
      }
      this->add_child(struct_inst_table);
    }
  } else {
    error_func();
  }
}

void SymbolTable::add_type(string name, string type, int size,
                           function<void()> error_func) {
  if (!get_where<Type>(t_types, [=](Type &t) { return t.name() == name; })) {
    t_types.push_back(Type(name, type, size));
  } else {
    error_func();
  }
}

void SymbolTable::add_method(string name, string r_type, vector<string> params,
                             string alias, function<void()> error_func) {
  if (!get_where<Method>(t_methods, [=](Method &m) {
        return m.name() == name && m.param_signature() == params;
      })) {
    t_methods.push_back(Method(name, r_type, params, alias));
  } else {
    error_func();
  }
}

shared_ptr<SymbolTable> SymbolTable::parent() { return t_parent; }
void SymbolTable::add_child(shared_ptr<SymbolTable> child) {
  t_children[child->id()] = child;
}
unordered_map<Method, shared_ptr<SymbolTable>, MethodHasher, MethodComparator> &
SymbolTable::children() {
  return t_children;
}

void insert_names(vector<string> &out, string name, int times) {
  vector<string> names(times, name);
  out.insert(out.end(), names.begin(), names.end());
}

void put_in_table(SymbolTable &table, SymbolTable &out,
                  vector<vector<string>> &env_names) {
  out.symbols().insert(out.symbols().end(), table.symbols().begin(),
                       table.symbols().end());
  insert_names(env_names[0], table.name(), table.symbols().size());
  out.types().insert(out.types().end(), table.types().begin(),
                     table.types().end());
  insert_names(env_names[1], table.name(), table.types().size());
  out.methods().insert(out.methods().end(), table.methods().begin(),
                       table.methods().end());
  insert_names(env_names[2], table.name(), table.methods().size());

  for (auto &[c_id, child] : table.children()) {
    put_in_table(*child, out, env_names);
  }
}

pair<SymbolTable, vector<vector<string>>> SymbolTable::flatten() {
  SymbolTable flattened_table;
  vector<vector<string>> env_names(3, vector<string>{});
  put_in_table(*this, flattened_table, env_names);
  return make_pair(flattened_table, env_names);
}