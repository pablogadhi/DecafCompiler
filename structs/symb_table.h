#ifndef SYMB_TABLE_H
#define SYMB_TABLE_H

#include "error_item.h"
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TableRow {
private:
  string row_name = "";
  string row_type = "";

public:
  TableRow(string, string);
  TableRow();
  ~TableRow();
  string name() const;
  string type();
};

class Symbol : public TableRow {
private:
  int s_size = -1;
  int s_offset = -1;

public:
  Symbol(string, string, int, int);
  Symbol();
  ~Symbol();
  int size();
  int offset();
};

class Type : public TableRow {
private:
  int t_size = -1;

public:
  Type(string, string, int);
  Type();
  ~Type();
  int size();
};

class Method : public TableRow {
private:
  vector<string> m_param_signature;

public:
  Method(string, string, vector<string> param_signature = vector<string>{});
  Method();
  ~Method();
  vector<string> param_signature() const;
};

struct MethodHasher {
  hash<string> str_hash;
  size_t operator()(const Method &key) const {
    size_t hashed_args = 0;
    for (auto &arg : key.param_signature()) {
      hashed_args += str_hash(arg);
    }
    return str_hash(key.name()) + hashed_args;
  }
};

struct MethodComparator {
  bool operator()(const Method &lmeth, const Method &rmeth) const {
    return lmeth.name() == rmeth.name() &&
           lmeth.param_signature() == rmeth.param_signature();
  }
};

class SymbolTable : public enable_shared_from_this<SymbolTable> {
private:
  Method t_id;

  vector<Symbol> t_symbols;
  vector<Type> t_types;
  vector<Method> t_methods;

  shared_ptr<SymbolTable> t_parent;
  unordered_map<Method, shared_ptr<SymbolTable>, MethodHasher, MethodComparator>
      t_children;

public:
  SymbolTable();
  SymbolTable(Method);
  SymbolTable(Method, shared_ptr<SymbolTable>);
  ~SymbolTable();
  void init_basic_types();
  Method &id();
  string name();
  vector<Symbol> &symbols();
  vector<Type> &types();
  vector<Method> &methods();
  int next_symbol_offset();
  void add_symbol(
      string, string, int, function<void()> = [] {});
  void add_type(
      string, string, int, function<void()> = [] {});
  void add_method(
      string, string, vector<string>, function<void()> = [] {});
  shared_ptr<SymbolTable> parent();
  void add_child(shared_ptr<SymbolTable>);
  unordered_map<Method, shared_ptr<SymbolTable>, MethodHasher, MethodComparator>
      &children();
  pair<SymbolTable, vector<vector<string>>> flatten();
};

template <class InfoType>
bool get_where(vector<InfoType> &table_vector,
               function<bool(InfoType &)> predicate, InfoType *out = nullptr) {
  auto iter = find_if(table_vector.begin(), table_vector.end(), predicate);
  if (iter != table_vector.end()) {
    if (out != nullptr) {
      *out = *iter;
    }
    return true;
  }
  return false;
}

template <class InfoType>
bool recursive_lookup(
    shared_ptr<SymbolTable> table,
    function<vector<InfoType>(shared_ptr<SymbolTable>)> vector_lambda,
    function<bool(InfoType &)> predicate, InfoType *out = nullptr) {
  vector<InfoType> vector_to_search = vector_lambda(table);
  if (!get_where(vector_to_search, predicate, out)) {
    if (table->parent() != nullptr) {
      return recursive_lookup(table->parent(), vector_lambda, predicate, out);
    } else {
      return false;
    }
  }
  return true;
}

template <class InfoType>
vector<InfoType> get_all_where(vector<InfoType> &table_vector,
                               function<bool(InfoType &)> predicate) {
  vector<InfoType> output_vec;
  copy_if(table_vector.begin(), table_vector.end(), back_inserter(output_vec),
          predicate);
  return output_vec;
}

#endif