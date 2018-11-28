#include <iostream>

bool is_array_cycle(int arr[], int arr_size) {
  if(arr_size == 0) return false;
  if(arr_size == 1 && (arr[0] == 0 || arr[0] == 1)) return true;

  int currentPos{0};
  for(int i = 0; i < arr_size; ++i) {
    //std::cout << "CurrPos: " << currentPos << " i: " << i << " arr[i]" << arr[currentPos] <<std::endl;
    if(arr[currentPos] == 0) return false;
    currentPos += arr[currentPos]; 
    currentPos = currentPos % arr_size;
    if(currentPos < 0) {
      currentPos += arr_size;
    }
    if(currentPos == 0 && i != arr_size - 1) {
      return false;
    }
  }

  return currentPos == 0;
}

int main(int argc, char** argv) {
  int arr[] = {2,3,-1,2,-1};
  auto arr_size = sizeof(arr)/sizeof(arr[0]);

  auto result = is_array_cycle(arr, arr_size);
  std::cout << "An array " << (result ? "is": "is not") << " a relative indices cycle\n";
  return 0;
}
