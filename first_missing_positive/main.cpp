#include <iostream>
#include <algorithm>

auto first_missing_positive(int* arr, size_t arr_size) {
  for(int i = 0; i < arr_size; i++) {
    while(i + 1 != arr[i]) {
      if(arr[i] >= arr_size || arr[i] < 0) {
        break;
      }
      if(arr[i] == arr[arr[i] - 1]) {
        std::cout << "breaking\n";
        break;
      }
      std::swap(arr[i], arr[arr[i] - 1]);
    }
  }

  for(int i=0;i<arr_size;i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  for(int i=0;i<arr_size;i++) {
    if(arr[i] != i + 1) {
      return i + 1;
    }
  }

  return static_cast<int>(arr_size);
}

int main(int argc, char** argv) {
  int arr[] = {5,4,1,2,7,5};
  constexpr auto arr_size = sizeof(arr)/sizeof(arr[0]);
  std::cout << "First missing positive: " << first_missing_positive(arr, arr_size) << std::endl;
  return 0;
}
