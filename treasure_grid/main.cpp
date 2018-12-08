#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>

class Treasures {
  public:
    Treasures(const int size, int** treasures):
      m_size(size),
      m_treasures(treasures),
      m_cache(nullptr) {

    }
    ~Treasures() {
      if(m_cache != nullptr) {
        std::cout << "Removing cache in destructor\n";
        remove_cache();
      }
    }

    void print_treasures() const {
      for(int row = 0; row < m_size; row++) {
        for(int col = 0; col < m_size; col++) {
          std::cout << std::setw(2) << m_treasures[row][col] << " ";
        }
        std::cout << std::endl;
      }
    }

    void print_cache() const {
      if(m_cache == nullptr) return;

      std::cout << std::endl;
      for(int row = 0; row < m_size; row++) {
        for(int col = 0; col < m_size; col++) {
          std::cout << std::setw(3) << m_cache[row][col] << " ";
        }
        std::cout << std::endl;
      }
    }

    auto max_treasure() {
      init_cache();
      for(int col = m_size - 1; col >= 0; col--) {
        for(int row = m_size - 1; row >= 0; row--) {
          int prev_max_in_row{0};
          int prev_max_in_col{0};
          if(row + 1 < m_size) {
            prev_max_in_col = m_cache[row + 1][col];
          }
          if(col + 1 < m_size) {
            prev_max_in_row = m_cache[row][col + 1];
          }
          m_cache[row][col] = m_treasures[row][col] + std::max({prev_max_in_col, prev_max_in_row});
        }
      }
      print_cache();
      auto result = m_cache[0][0];
      remove_cache();
      return result;
    }

  private:
    size_t m_size;
    int** m_treasures;
    int** m_cache;

    void init_cache() {
      if(m_cache != nullptr) {
        remove_cache();
      }

      m_cache = new int*[m_size];
      for(int row = 0; row < m_size; row++) {
        m_cache[row] = new int[m_size];
      }
    }

    void remove_cache() {
      for(int row = 0; row < m_size; row++) {
        delete[](m_cache[row]);
      }
      delete[](m_cache);
      m_cache = nullptr;
    }
};

int main(int argc, char** argv) {
  constexpr auto size = 10;
  int** treasures = new int*[size];
  for(int i =0; i < size; i++) {
    treasures[i] = new int[size];
  }
  for(int row = 0; row < size; row++) {
    for(int col = 0; col < size; col++) {
      treasures[row][col] = std::rand() % 10;
    }
  }

  Treasures t{10, treasures};
  t.print_treasures();
  std::cout << "Found the best result: " << t.max_treasure() << "\n";

  for(int i = 0; i < size; i++) {
    delete[](treasures[i]);
  }
  delete[](treasures);
  return 0;
}
