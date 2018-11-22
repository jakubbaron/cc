#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

bool is_words_cycle(const std::vector<std::string>& words) {
  if(words.size() < 1) return false; //can't make a circle if there aren't at least 2 words

  std::unordered_map<char, int> char_count;
  for(const auto& word: words) {
    if(word.empty()) continue;
    char_count[*word.cbegin()]++;
    char_count[*word.rbegin()]--;
  }

  if(char_count.empty()) return false;

  for(const auto& item: char_count) {
    if(item.second != 0) return false;
  }

  return true;
}

int main(int argc, char** argv) {
  //std::vector<std::string> words { "cycle", "radio", "cardio", "oscyloscope", "elephant" };
  std::vector<std::string> words { "cne", "enc", "ono"};
  std::cout << "Is a words cycle? " << (is_words_cycle(words) ? "YES" : "NO") << std::endl;
}
