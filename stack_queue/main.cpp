#include <iostream>
#include <stack>

template<class T>
T dequeue_from_stack(std::stack<T>& s) {
  if(s.size() == 1) {
    T val = s.top();
    s.pop();
    return val;
  }
  T curr_val = s.top();
  s.pop();
  auto result = dequeue_from_stack(s);
  s.push(curr_val);

  return result;
}


int main(int argc, char** argv) {
  std::stack<int> s;
  for(int i=0;i<10;i++) {
    s.push(i);
  }
  std::cout << "Elements in stack: " << std::endl;
  while(!s.empty()) {
    std::cout << s.top() << std::endl;
    s.pop();
  }

  for(int i=0;i<10;i++) {
    s.push(i);
  }

  std::cout << "Dequeueing:" << std::endl;
  while(!s.empty()) {
    std::cout << dequeue_from_stack(s) << std::endl;
  }
  return 0;
}
