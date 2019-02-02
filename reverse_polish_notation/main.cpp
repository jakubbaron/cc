#include <iostream>
#include <stack>

auto calculate(const std::string& input) noexcept -> double {
  static const std::string operators = "+-/*";
  double result = 0.0;
  if(input.empty()) {
    return result;
  }
  std::stack<double> calc;
  for(const auto& c: input) {
    if(operators.find(std::string(1, c)) == std::string::npos) {
      calc.emplace(static_cast<double>(c - '0'));
      continue;
    }
    if(calc.empty()) {
      return result; 
    }
    double a = calc.top();
    calc.pop();
    double b = a;
    if(!calc.empty()) {
      b = calc.top(); 
      calc.pop();
    }
    switch(c) {
      case '+':
        calc.emplace(a+b);
        break;
      case '-':
        calc.emplace(a-b);
        break;
      case '/':
        calc.emplace(a/b);
        break;
      case '*':
        calc.emplace(a*b);
        break;
    }
  }
  result = calc.top();
  calc.pop();
  if(!calc.empty()) { 
    std::cerr << "Stack wasn't empty at the end! :o" << std::endl;
  }
  return result;
}

int main(int argc, char** argv) {
  std::string input = "21+3**";
  const auto result = calculate(input);
  std::cout << result << std::endl;
  return EXIT_SUCCESS;
}
