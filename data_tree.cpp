#include "data_tree.h"

DataNode::DataNode() {}
DataNode::DataNode(string n_text) : text(n_text) {}
DataNode::DataNode(string n_text, shared_ptr<DataNode> n_parent)
    : text(n_text), parent(n_parent) {}
DataNode::~DataNode() {}
string DataNode::get_text() { return text; }
bool DataNode::has_been_visited() { return visited; }
vector<shared_ptr<DataNode>> DataNode::get_children() { return children; }
shared_ptr<DataNode> DataNode::get_parent() { return parent; }
void DataNode::add_child(shared_ptr<DataNode> child) {
  children.push_back(child);
}
void DataNode::visit() { visited = true; }

void DataNode::set_text(string new_text) { text = new_text; }
shared_ptr<DataNode> DataNode::get_first_not_visited() {
  for (auto &c : children) {
    if (!c->has_been_visited()) {
      return c;
    }
  }
  return nullptr;
}