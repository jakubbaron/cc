#include <iostream>

int findMin(int arr[], int low, int high) {
  if ( low == high) {
    return arr[low];
  }
  if( high - low == 1) {
    return std::min(arr[low], arr[high]);
  }

  auto mid = low + (high - low) /2;
  if(arr[low] < arr[high]) {
    return arr[low];
  }
  if (arr[mid] > arr[low]) {
    return findMin(arr, mid, high);
  } else {
    return findMin(arr, low, mid);
  }
}

int main(int argc, char** argv) {
  int arr[] = {5,6,7,8,9,0,1,2,3,4};
  auto arr_size = sizeof(arr)/sizeof(arr[0]);
  std::cout << findMin(arr, 0, arr_size - 1) << std::endl;
  return 0;
}
