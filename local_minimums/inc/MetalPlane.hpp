#include <iostream>
#include <cstdlib>
#include <iomanip>

class MetalPlane {
  public:
    MetalPlane(const int size, const int init_height) {
      m_size = size;
      m_plane = new int*[m_size];
      for(auto i = 0; i < m_size; i++) {
        m_plane[i] = new int[m_size];
      }
      for(auto row = 0; row < m_size; row++) {
        for(auto col = 0; col < m_size; col++) {
          m_plane[row][col] = init_height;
        }
      }
    }
    ~MetalPlane() {
      if(m_plane) {
        for(auto i = 0; i < m_size; i++) {
          delete[] m_plane[i];
        }
        delete[] m_plane;
      } 
    }
    auto get_size() const {
      return m_size;
    }
    void print_plane() const {
      for(auto row = 0; row < m_size; row++) {
        for(auto col = 0; col < m_size; col++) {
          std::cout << std::setw(2) << m_plane[row][col] << " ";
        }
        std::cout << std::endl;
      }
    }
  private:
    int** m_plane;
    int m_size;
};
