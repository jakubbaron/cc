#include <iostream>

void merge(int arr[], int left, int middle, int right) {
  int n1 = middle - left + 1;
  int n2 = right - middle;
  int L[n1], R[n2];

  for(int i = 0; i < n1; i++) {
    L[i] = arr[left + i];
  }
  for(int j = 0; j < n2; j++) { 
    R[j] = arr[1 + middle + j];
  }
  int i{0},j{0},k{left};
  while (i < n1 && j < n2) {
    if(L[i] <= R[j]) { 
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++; k++;
  }
  while (j < n2) {
    arr[k] = R[j];
    j++; k++;
  }
}

void mergeSort(int arr[], int left, int right) {
  if(left >= right) return;

  int middle = left + (right - left) / 2;
  mergeSort(arr, left, middle);
  mergeSort(arr, middle + 1, right);

  merge(arr, left, middle, right);
}

void printArray(int A[], int size) {
    int i{0};
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main(int argc, char** argv) {
  int arr[] = {3,1,5,7,23,4,22};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  printArray(arr, arr_size);
  mergeSort(arr, 0, arr_size - 1);
  printArray(arr, arr_size);
}
