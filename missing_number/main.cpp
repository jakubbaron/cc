#include <iostream>

int missing_number(int arr[], int arr_size) {
  for(int i = 0; i < arr_size; i++) {
    while(i != arr[i]) {
      if(arr[i] < 0 || arr[i] > arr_size) break;
      if(arr[arr[i]] == arr[i]) break;
      std::swap(arr[arr[i]], arr[i]);
    }
  }

  for(int i = 0; i< arr_size; i++) {
    if(i != arr[i]) return i;
  }

  return -1;
}

int main(int argc, char** argv) {
  int arr[] = {1,2,0,4,3,6,7};
  // int arr[] = {1,2,3,4};
  auto arr_size = sizeof(arr)/sizeof(arr[0]);
  std::cout << "Missing number is[" << missing_number(arr, arr_size) << "]\n";

  return 0;
}
