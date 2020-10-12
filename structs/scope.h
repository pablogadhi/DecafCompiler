#ifndef SCOPE_H
#define SCOPE_H

#include "symb_table.h"
#include "triple.h"

class Scope {
private:
  SymbolTable s_table;
  TACode s_code;

public:
  Scope();
  ~Scope();
};

Scope::Scope() {}

Scope::~Scope() {}

#endif