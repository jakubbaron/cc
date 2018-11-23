#include <iostream>
// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order. You may assume no duplicates in the array.
// 
// Here are few examples.
// [1,3,5,6], 5 -> 2
// [1,3,5,6], 2 -> 1
// [1,3,5,6], 7 -> 4
// [1,3,5,6], 0 -> 0

int insert_in_order(int arr[], int arr_size, int el) {
  int l = 0;
  int r = arr_size - 1;

  while ( l <= r ) {
    int m = (r + l) / 2;
    //std::cout << "m " << m << " l " << l << " r " << r << "\n";
    if(el > arr[m]) {
      l = m + 1;
    } 
    else if(el < arr[m]) {
      r = m - 1; 
    } else {
      return m;
    }
  }
  return l;
}

int main(int argc, char** argv) {
  int arr[] = {1,3,5,6};
  auto arr_size = sizeof(arr)/sizeof(arr[0]);
  int el = 12;
  auto pos = insert_in_order(arr, arr_size, el);
  std::cout << "Element[" << el << "] would be inserted at position[" << pos << "]\n";
  return 0;
}
