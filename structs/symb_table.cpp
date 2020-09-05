#include "symb_table.h"
#include <algorithm>

TableRow::TableRow(string name, string type, string env)
    : row_name(name), row_type(type), row_env(env) {}
TableRow::TableRow() {}
TableRow::~TableRow() {}
string TableRow::name() { return row_name; }
string TableRow::type() { return row_type; }
string TableRow::env() { return row_env; }

Symbol::Symbol(string name, string type, string env, int size, int offset)
    : TableRow(name, type, env), s_size(size), s_offset(offset) {}
Symbol::Symbol() : TableRow() {}
Symbol::~Symbol() {}
int Symbol::size() { return s_size; }
int Symbol::offset() { return s_offset; }

Type::Type(string name, string type, string env, int size)
    : TableRow(name, type, env), t_size(size) {}
Type::Type() : TableRow() {}
Type::~Type() {}
int Type::size() { return t_size; }

Method::Method(string name, string type, string env,
               vector<string> param_signature)
    : TableRow(name, type, env), m_param_signature(param_signature) {}
Method::Method() : TableRow() {}
Method::~Method() {}
vector<string> &Method::param_signature() { return m_param_signature; }

SymbolTable::SymbolTable() {}
SymbolTable::SymbolTable(Method id) : t_id(id) {}
SymbolTable::SymbolTable(Method id, shared_ptr<SymbolTable> parent)
    : t_id(id), t_parent(parent) {}
SymbolTable::~SymbolTable() {}

void SymbolTable::init_basic_types() {
  t_types.push_back(Type("char", "basic", "__global__", 1));
  t_types.push_back(Type("boolean", "basic", "__global__", 1));
  t_types.push_back(Type("int", "basic", "__global__", 4));
}

Method &SymbolTable::id() { return t_id; }
string SymbolTable::name() { return t_id.name(); }
vector<Symbol> &SymbolTable::symbols() { return t_symbols; }
vector<Type> &SymbolTable::types() { return t_types; }
vector<Method> &SymbolTable::methods() { return t_methods; }

int SymbolTable::next_symbol_offset() {
  int offset = 0;
  if (!t_symbols.empty()) {
    auto last_symb = t_symbols.back();
    offset = last_symb.offset() + last_symb.size();
  }
  return offset;
}

void SymbolTable::add_symbol(string name, string type, string env, int size,
                             function<void()> error_func) {
  if (!get_where<Symbol>(t_symbols,
                         [=](Symbol &s) { return s.name() == name; })) {
    t_symbols.push_back(Symbol(name, type, env, size, next_symbol_offset()));

    Type type_ctr;
    get_where<Type>(
        t_types, [&](Type &t) { return t.name() == type; }, &type_ctr);
    if (type_ctr.type() == "struct") {
      auto struct_table = make_shared<SymbolTable>(
          Method(name, type, this->name()), shared_from_this());
      auto struct_members = get_all_where<Type>(
          t_types, [&](Type &t) { return t.env() == type; });
      for (auto &memb : struct_members) {
        struct_table->add_symbol(memb.name(), memb.type(), name, memb.size());
      }
      this->add_child(struct_table);
    }
  } else {
    error_func();
  }
}

void SymbolTable::add_type(string name, string type, string env, int size,
                           function<void()> error_func) {
  if (!get_where<Type>(t_types, [=](Type &t) { return t.name() == name; })) {
    t_types.push_back(Type(name, type, env, size));
  } else {
    error_func();
  }
}

void SymbolTable::add_method(string name, string r_type, string env,
                             vector<string> params,
                             function<void()> error_func) {
  if (!get_where<Method>(t_methods, [=](Method &m) {
        return m.name() == name && m.param_signature() == params;
      })) {
    t_methods.push_back(Method(name, r_type, env, params));
  } else {
    error_func();
  }
}

shared_ptr<SymbolTable> SymbolTable::parent() { return t_parent; }
void SymbolTable::add_child(shared_ptr<SymbolTable> child) {
  t_children[child->id().name()] = child;
}
map<string, shared_ptr<SymbolTable>> &SymbolTable::children() {
  return t_children;
}

void put_in_table(SymbolTable &table, SymbolTable &out) {
  out.symbols().insert(out.symbols().end(), table.symbols().begin(),
                       table.symbols().end());
  out.types().insert(out.types().end(), table.types().begin(),
                     table.types().end());
  out.methods().insert(out.methods().end(), table.methods().begin(),
                       table.methods().end());

  for (auto &[c_id, child] : table.children()) {
    put_in_table(*child, out);
  }
}

SymbolTable SymbolTable::flatten() {
  SymbolTable flattened_table;
  put_in_table(*this, flattened_table);
  return flattened_table;
}