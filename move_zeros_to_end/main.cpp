#include <iostream>
#include <algorithm>

void move_zeros_to_end(int arr[], int arr_size) {
  if(arr_size == 1) return;
  int zero_el{0}, non_zero_el{0};
  while(zero_el < arr_size && arr[zero_el] != 0) {
    zero_el++;
  }
  if(zero_el == arr_size) return;

  while(non_zero_el < arr_size && arr[non_zero_el] == 0) {
    non_zero_el++;
  }
  if(non_zero_el == arr_size) return; 

  for(; zero_el < arr_size; zero_el++) {
    if(arr[zero_el] != 0) {
      continue;
    }
    std::swap(arr[zero_el], arr[non_zero_el]);
    while(non_zero_el < arr_size && arr[non_zero_el] == 0) {
      non_zero_el++;
    }

    if(non_zero_el == arr_size) break;
  }
}

void print_array(int arr[], int arr_size) {
  for(int i=0; i < arr_size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

int main(int argc, char** argv) {
  int arr[] = { 0, 0, 1, 0, 3, 0 };
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  print_array(arr, arr_size);
  move_zeros_to_end(arr, arr_size);
  print_array(arr, arr_size);
  return 0;
}
