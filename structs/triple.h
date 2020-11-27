#ifndef TRIPLE_H
#define TRIPLE_H

#include <memory>
#include <string>
#include <vector>

using namespace std;

enum class Operator {
  ASSIGN,
  MUL,
  DIV,
  MOD,
  SUM,
  MINUS,
  LESS,
  LESS_EQ,
  GREATER,
  GREATER_EQ,
  EQ,
  NOT_EQ,
  AND,
  OR,
  NOT,
  JUMP,
  IF,
  IFFALSE,
  LABEL,
  CALL,
  RET,
  PARAM,
  PUSH,
  POP
};

class Address {
private:
  int a_value = -1;

public:
  Address(int);
  virtual ~Address() = default;
  int value();
  void change(int);
};

class Literal : public Address {
private:
  string l_type = "";
  string l_value = "";

public:
  Literal(string, string);
  ~Literal();
  string type();
  string value();
};

class Triple : public Address {
private:
  Operator t_op;
  shared_ptr<Address> t_arg0;
  shared_ptr<Address> t_arg1;
  bool t_temp_offset = false;

public:
  Triple(Operator, shared_ptr<Address>, shared_ptr<Address> arg1 = nullptr,
         bool temp_offset = false);
  Triple(Operator);
  ~Triple();
  Operator op();
  shared_ptr<Address> &arg0();
  shared_ptr<Address> &arg1();
  void set_arg0(shared_ptr<Address>);
  void set_arg1(shared_ptr<Address>);
  bool temp_offset();
};

class Temp : public Address {
private:
  string t_name = "";
  bool t_as_offset = false;

public:
  Temp(string);
  ~Temp();
  string name();
  bool as_offset();
  void set_as_offset(bool);
};

class TACode {
private:
  vector<shared_ptr<Triple>> code_vec;
  int label_counter = 0;

  void optimize_code();

public:
  TACode();
  ~TACode();
  vector<shared_ptr<Triple>> &code();
  shared_ptr<Address> gen(Operator, shared_ptr<Address>,
                          shared_ptr<Address> arg1 = nullptr,
                          bool temp_offset = false);
  pair<vector<Triple>, string> translate();
  vector<int> make_list(int);
  vector<int> merge(vector<int>, vector<int>);
  void back_patch(vector<int>, int);
  int next_instr();
  string new_label(string prefix = "_LOCAL_");
};

#endif