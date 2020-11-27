#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include "structs/symb_table.h"
#include "structs/triple.h"
#include <map>
#include <string>

using namespace std;

class CodeGenerator {
private:
  shared_ptr<SymbolTable> symbol_table;
  vector<Triple> inter_code;
  string gen_code;
  string main_name;
  string end_label;
  map<string, string> basic_init_vals = {
      {"int", "0"}, {"boolean", "0"}, {"char", "0x00"}};
  map<int, string> size_prefixes = {{1, "byte"}, {4, "dword"}};

  void init_code();
  void end_code();

public:
  CodeGenerator(vector<Triple>, shared_ptr<SymbolTable> &);
  ~CodeGenerator();
  void generate(string);
  string operand_to_str(shared_ptr<Address>, vector<Triple> &);
  void translate_to_asm();
  string convert_reg(string, int);
};

#endif