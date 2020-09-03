#ifndef DATA_TREE_H
#define DATA_TREE_H

#include <memory>
#include <string>
#include <vector>

using namespace std;

class DataNode {
private:
  string text = "";
  bool visited = false;
  vector<shared_ptr<DataNode>> children;
  shared_ptr<DataNode> parent;

public:
  DataNode();
  DataNode(string);
  DataNode(string, shared_ptr<DataNode>);
  ~DataNode();
  string get_text();
  bool has_been_visited();
  vector<shared_ptr<DataNode>> get_children();
  shared_ptr<DataNode> get_parent();
  void add_child(shared_ptr<DataNode>);
  void visit();
  void set_text(string);
  shared_ptr<DataNode> get_first_not_visited();
};

#endif