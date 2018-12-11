#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "MetalPlane.hpp"

constexpr auto size = 10;

void print_array(int arr[][size], int arr_size = size) {
  for(auto row = 0; row < size; row++) {
    for(auto col = 0; col < size; col++) {
      std::cout << std::setw(2) << arr[row][col] << " ";
    }
    std::cout << std::endl;
  }
}


int main(int argc, char** argv) {
  int arr[size][size];
  for(auto row = 0; row < size; row++) {
    for(auto col = 0; col < size; col++) {
      arr[row][col] = 5 + (-5 + std::rand() % 10);
    }
  }

  MetalPlane mp(size, 10);
  mp.print_plane();
  std::cout << std::endl;
  print_array(arr, size);
  return 0;
}
