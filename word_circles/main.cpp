#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

bool is_words_cycle(const std::vector<std::string>& words) {
  if(words.size() < 1) return false; //can't make a circle if there aren't at least 2 words

  std::unordered_map<char, int> char_count;
  std::vector<std::string> count_later;
  for(const auto& word: words) {
    if(word.empty()) continue;
    char start = *word.cbegin();
    char end = *word.crbegin();

    if(start == end) {
      count_later.push_back(word);
      continue;
    }
    char_count[start]++;
    char_count[end]--;
  }

  for(const auto& word: count_later) {
    char start = *word.cbegin(); // no need to end, they're the same
    if(!char_count.count(start)) return false; //can't use that word in wrods cycle
    if(char_count[start] % 2 != 0) return false; // we don't need to aleer the counter, just check if it's even
  }

  if(char_count.empty()) return false;

  for(const auto& item: char_count) {
    if(item.second != 0) return false;
  }

  return true;
}

int main(int argc, char** argv) {
  //std::vector<std::string> words { "cycle", "radio", "cardio", "oscyloscope", "elephant" };
  std::vector<std::string> words { "cne", "ono", "enc"};
  std::cout << "Is a words cycle? " << (is_words_cycle(words) ? "YES" : "NO") << std::endl;
}
