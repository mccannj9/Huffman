#include <iostream>
#include <fstream>
#include <map>

std::map<char, double> build_char_count_dict(std::ifstream& text) {
  std::map<char, double> char_dict;
  char c;

  while (text.get(c)) {
    auto key_search = char_dict.find(c);
    if (key_search != char_dict.end()) {
      char_dict[c] += 1.0;
    }
    else {
      char_dict[c] = 1.0;
    }
  }

  return char_dict;
}

double normalize_to_freq(std::map<char, double>& input_dict) {
  double total_chars {0};

  for (auto x : input_dict) {
    total_chars += x.second;
  }

  for (auto x : input_dict) {
    input_dict[x.first] /= total_chars;
  }

  return total_chars;
}



int main(int argc, char** argv) {

  std::ifstream text_data;
  text_data.open(argv[1]);
  std::map<char, double> char_dict = build_char_count_dict(text_data);
  text_data.close();

  double total_chars = normalize_to_freq(char_dict);

  for (auto x : char_dict) {
    std::printf("%c, %f\n", x.first, x.second);
  }

  std::printf("Total characters = %d\n", (int)total_chars);

  return 0;
}
