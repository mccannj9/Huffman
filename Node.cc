#include <iostream>
#include <string>

struct Node {
  std::string value;
  double freq;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;

  Node();

  Node(std::string value, double freq) : value(value), freq(freq) {}

  Node(Node* left_child, Node* right_child);

  void update_parent(Node* new_parent);
  bool is_leaf();
  bool is_root();
};

void Node::update_parent(Node* new_parent) {
  parent = new_parent;
}

Node::Node() {
  value = 'x';
  freq = 0.0;
}


Node::Node(Node* left_child, Node* right_child) {
  left = left_child;
  right = right_child;
  value = left->value + "_" + right->value;
  freq = left->freq + right->freq;
  parent = nullptr;
}


bool Node::is_leaf() {
  if (!left && !right) {
    return true;
  }
  return false;
}


bool Node::is_root() {
  if (parent == nullptr) {
    return true;
  }
  return false;
}

int main() {
  Node node;
  node.left = nullptr;
  node.right = nullptr;
  node.parent = nullptr;

  std::printf("Is leaf? %d\n", (int)node.is_leaf());
  std::printf("Is root? %d\n", (int)node.is_root());

  Node child_left = Node("c", 0.1);
  Node child_right = Node("a", 0.2);
  Node root = Node(&child_left, &child_right);
  root.left->update_parent(&root);
  root.right->update_parent(&root);

  std::printf("Root value %s, Root freq %f\n", root.value.c_str(), root.freq);
  std::printf("Root is leaf? %d\n", (int)root.is_leaf());
  std::printf("Root is root? %d\n", (int)root.is_root());
  std::printf("Left is leaf? %d\n", (int)root.left->is_leaf());
  std::printf("Right is leaf? %d\n", (int)root.right->is_leaf());
  std::printf("Left is root? %d\n", (int)root.left->is_root());
  std::printf("Right is root? %d\n", (int)root.right->is_root());
  return 0;
}
