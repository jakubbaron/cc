#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

//void permutations(std::string in, std::string out, std::unordered_set<std::string>& results) {
//  if(in.length() == 0) {
//    results.insert(out);
//  }
//
//  for(int i = 0; i < in.size(); i++) { 
//    permutations(in.substr(1), out + in[0], results);
//    std::rotate(in.begin(), in.begin() + 1, in.end());
//  }
//}

std::unordered_set<std::string> permutations(std::string in, char c) {
  if(in.length() == 1) {
    return std::unordered_set<std::string>{in + c, c + in};
  }

  std::unordered_set<std::string> results;
  for(auto item: permutations(in.substr(0, in.length() - 1), in[in.length() -1])) {
    for(int i = 0; i <= item.length(); i++) {
      results.insert(item.substr(0,i) + c + item.substr(i));
    }
  }

  return results;
}

std::unordered_set<std::string> permutations(std::string in) {
  std::unordered_set<std::string> results;
  results = permutations(in.substr(0, in.length() - 1), in[in.length() - 1]); 

  return results;
}

int main(int argc, char** argv) {
  std::string input = "abc";
  for(const auto& item: permutations(input)) {
    std::cout << item << std::endl;
  }
}
