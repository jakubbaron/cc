#include <iostream>
#include <vector>
#include <algorithm>
//

template<class T>
auto partition(std::vector<T>& vec, const int low, const int high) noexcept -> int {
  const auto pivot = vec[high]; // pivot
  auto i = low - 1; // Index of smaller element
  for(int j = low; j <= high - 1; j++) {
    if(vec[j] <= pivot) {
      i++;
      std::swap(vec[i], vec[j]);
    }
  }
  std::swap(vec[i + 1], vec[high]);
  return i + 1;
}

template<class T>
auto quick_sort(std::vector<T>& vec, const int low, const int high) noexcept -> void {
  if(vec.empty()) {
    return;
  }
  if(low >= high) {
    return;
  }

  const auto pi = partition(vec, low, high);
  quick_sort(vec, low, pi - 1);
  quick_sort(vec, pi + 1, high);
}

template <class T>
auto display_vec(const std::vector<T>& vec) noexcept -> void {
  for(const auto& item: vec) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char** argv) {
  std::vector<int> vec = {1, 5, 7, 3, 1, 4, 5, 6, -5};
  display_vec(vec);
  quick_sort(vec, 0, vec.size() - 1);
  display_vec(vec);
  return EXIT_SUCCESS;
}
