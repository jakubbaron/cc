#include <iostream>

int remove_duplicates(int arr[], int arr_size) {
  if(arr_size == 1) {
    return arr_size;
  }

  int i{1}, j{0};
  for(; i < arr_size; i++) {
    if(arr[i] == arr[j]) {
      continue;
    } 
    arr[++j] = arr[i++];
  }
  return j + 1;
}

int main(int argc, char** argv) {
  int arr[] = { 1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3 };
  auto arr_size = sizeof(arr)/sizeof(arr[0]);

  std::cout << "Number of unique elements[" << remove_duplicates(arr, arr_size) << "]\n";
  return 0;
}
