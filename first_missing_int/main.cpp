#include <iostream>
#include <algorithm>


int first_missing_int(int arr[], int arr_size) {
  int i={0};
  for(; i< arr_size; i++) {
    while(i != arr[i] + 1) {
      if(arr[i] < 0 || arr[i] >= arr_size) {
        break;
      }
      if(arr[i] == arr[arr[i] - 1]) {
        break;
      }
      std::swap(arr[arr[i] - 1], arr[i]);
    }
  }

  for(i = 0; i < arr_size; i++) {
    if(arr[i] != i + 1) {
      return i + 1;
    }
  }

  return arr_size;
}

int main(int argc, char** argv) {
  //int arr[] = {1, 2, 0, 4};
  int arr[] = {3,4,-1,1};
  auto arr_size = sizeof(arr)/sizeof(arr[0]);
  std::cout << "First missing int[" << first_missing_int(arr, arr_size) << "]\n";
  return 0;
}
