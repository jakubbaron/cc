#include <iostream>
#include <stack>

template<class T>
class QueueStack {
  public:
    T dequeue() {
      if(s.size() == 1) {
        T val = s.top();
        s.pop();
        return val;
      }
      T curr_val = s.top();
      s.pop();
      auto result = dequeue();
      s.push(curr_val);

      return result;
    }
    void enqueue(T val) {
      s.push(val);
    }
    bool empty() const {
      return s.empty();
    }

  private:
    std::stack<T> s;
};

template<class T>
class QueueTwoStacks {
  public:
    T dequeue() {
      if(!dequeue_s.empty()) {
        T val = dequeue_s.top();
        dequeue_s.pop();
        return val;
      }
      while(!enqueue_s.empty()) { 
        T val = enqueue_s.top();
        enqueue_s.pop();
        dequeue_s.push(val);
      }
      return dequeue();
    }

    void enqueue(T val) {
      enqueue_s.push(val);
    }
    bool empty() const {
      return enqueue_s.empty() && dequeue_s.empty();
    }

  private:
    std::stack<T> enqueue_s;
    std::stack<T> dequeue_s;
};


int main(int argc, char** argv) {
  QueueStack<int> qs;
  QueueTwoStacks<int> q2s;
  for(int i=0;i<10;i++) {
    qs.enqueue(i);
    q2s.enqueue(i);
  }

  std::cout << "Dequeueing 1 Stack Queue:" << std::endl;
  while(!qs.empty()) {
    std::cout << qs.dequeue() << std::endl;
  }

  std::cout << "Dequeueing 2 Stacks Queue:" << std::endl;
  while(!q2s.empty()) {
    std::cout << q2s.dequeue() << std::endl;
  }
  return 0;
}
