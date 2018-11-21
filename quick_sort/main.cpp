#include <iostream>
#include <algorithm>

int partition(int arr[], int low, int high) {
  auto pivot = arr[high];
  int i = low - 1;
  for(int j = low; j <= high - 1; j++) { 
    //if current element is smaller than or equal to pivot
    if(arr[j] <= pivot) {
      i++; // increment index of smaller element
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i+1], arr[high]);
  return i + 1;
}

void quickSort(int arr[], int low, int high) {
  if(low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void printArray(int A[], int size) {
    int i{0};
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(int argc, char** argv) {
  int arr[] = {10, 80, 30, 90, 40, 50, 70};
  const auto arr_size = sizeof(arr)/sizeof(arr[0]);
  std::cout << arr_size << std::endl;
  printArray(arr, arr_size);
  quickSort(arr, 0, arr_size - 1);
  printArray(arr, arr_size);
  return 0;
}
