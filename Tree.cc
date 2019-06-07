#include <iostream>
#include <string>

struct Node {
  std::string value;
  double freq;
  Node* left;
  Node* right;
  Node* parent;

  Node();
  Node(std::string value, double freq) : value(value), freq(freq){}
  Node(Node* left_child, Node* right_child); //, std::string character, double frequency);

  bool is_leaf();
  bool is_root();
};

Node::Node() {
  value = 'x';
  freq = 0.0;
  left = nullptr;
  right = nullptr;
  parent = nullptr;
}


Node::Node(Node* left_child, Node* right_child) {//, std::string s, double f) {
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
  std::printf("Root value %s, Root freq %f\n", root.value.c_str(), root.freq);
  std::printf("Root is leaf? %d\n", (int)root.is_leaf());
  std::printf("Root is root? %d\n", (int)root.is_root());
  return 0;
}
