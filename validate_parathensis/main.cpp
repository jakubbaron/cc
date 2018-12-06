#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>

bool validate_parathensis(const std::string& input) {
  constexpr char circle_open = '(';
  constexpr char circle_close = ')';
  constexpr char curly_open = '{';
  constexpr char curly_close = '}';
  constexpr char square_open = '[';
  constexpr char square_close = ']';
  const static std::unordered_set<char> closing = {circle_close, curly_close, square_close};
  const static std::unordered_set<char> opening = {circle_open, curly_open, square_open};

  std::stack<char> parathensis;
  for(const auto& c: input) {
    // if the first parathensis is closing, it can't be valid
    if(parathensis.empty() && closing.count(c)) {
      return false;
    }
    if(!opening.count(c) && !closing.count(c)) {
      std::cout << "Continuing\n";
      continue;
    }
    if(opening.count(c)) {
      parathensis.push(c);
    } else if(closing.count(c)) {
      const auto last_parathensis = parathensis.top();
      if(closing.count(last_parathensis)) {
        return false;
      }
      if(last_parathensis == circle_open && c != circle_close) {
        return false;
      } else if (last_parathensis == curly_open && c != curly_close) {
        return false;
      } else if (last_parathensis == square_open && c != square_close) {
        return false;
      }
      parathensis.pop();
    }
  }

  return parathensis.empty();
}

int main(int argc, char** argv) {
  const std::string in = { "{{[[]]}}" };
  const auto valid_para = validate_parathensis(in);
  std::cout << "Input is " << (valid_para ? "": "not ") << "valid" << std::endl;
  return EXIT_SUCCESS;
}
