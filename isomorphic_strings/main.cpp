#include <iostream>
#include <string> 
#include <map>

bool are_isomorphic(const std::string& str1, const std::string& str2) {
  if(str1.length() != str2.length()) return false;

  std::map<char, char> char_map; 
  for(int i=0; i < str1.length(); i++) {
    const char c1 = str1[i];
    const char c2 = str2[i];
    if(char_map.count(c1)) {
      if(char_map[c1] != c2) { 
        return false;
      } else {
        continue;
      }
      char_map[c1] = c2;
    }
  }
  return true;
}

int main(int argc, char** argv) {
  std::string str1;
  std::string str2;
  std::cout << "Give str1: ";
  std::cin >> str1;
  std::cout << "Give str2: ";
  std::cin >> str2;
  std::cout << "Given strings are " << (are_isomorphic(str1, str2) ? "" : "not ") << "isomorphic" << std::endl;

  return 0;
}
