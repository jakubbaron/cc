#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>

using HeighMap = std::vector<std::vector<double> >;

class Tool {
  public: 
    Tool() = default;
    HeighMap get_height_map() {
      return m_heigh_map;  
    }

  protected:
    HeighMap m_heigh_map;
};


class EndMill: public Tool {
  public:
    bool in_range(int x, int y) const { 
      return ((x - m_D/2.0)*(x - m_D/2.0) + (y - m_D/2.0)*(y - m_D/2.0)) <= ((m_D/2.0) * (m_D/2.0));
    }

    EndMill(unsigned int D, unsigned int dimension):
      m_D(D) {
        if(m_D > dimension) {
          throw std::invalid_argument("Resulting HeighMap will be too small");
        }
        for(auto i = 0; i < dimension; i++) {
          m_heigh_map.emplace_back(std::vector<double>(dimension, 100.0));
        }
      
        for(auto x = 0; x < m_heigh_map.size(); x++) {
          for(auto y = 0; y < m_heigh_map[x].size(); y++) {
            if(!in_range(x,y)) {
              continue;
            }
            m_heigh_map[x][y] = 0;
          }
        }
    }

    void print_height_map() const {
      for(const auto& row: m_heigh_map) {
        for(const auto& height: row) {
          std::cout << std::setw(4) <<  height << " ";
        }
        std::cout << std::endl;
      }
    }
  private:
    const unsigned int m_D;
};

int main(int argc, char** argv) {

  EndMill e{17, 20};
  e.print_height_map();

  return 0;
}
