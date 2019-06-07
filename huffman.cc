#include <iostream>
#include <fstream>

#include <map>

struct Node {
  char value;
  double freq;
  Node* left;
  Node* right;
  Node* parent;

  Node(char value, double freq) : value(value), freq(freq), left(nullptr), right(nullptr)
  {}

};

int main(int argc, char** argv) {
  std::map<char, double> char_dict;

  std::ifstream text_data;
  text_data.open(argv[1]);

  char c;
  while (text_data.get(c)) {
    std::printf("%c", c);
    auto key_search = char_dict.find(c);
    if (key_search != char_dict.end()) {
      char_dict[c] += 1.0;
    }
    else {
      char_dict[c] = 1.0;
    }
  }

  text_data.close();
  std::printf("\n");

  int total_chars {0};
  for (std::map<char, double>::iterator iter = char_dict.begin(); iter != char_dict.end(); iter++) {
    auto key = iter->first;
    auto val = iter->second;
    std::printf("%c, %f\n", key, val);
    total_chars += (int)val;
  }
  std::printf("Total characters = %d\n", total_chars);

  return 0;
}
