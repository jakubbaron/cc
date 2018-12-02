#include <iostream>
#include <set>

bool is_double_array_cycle(int arr[], int arr_size) {
  int position = 0;
  int i = 0;
  std::set<int> visited;
  for(; i < arr_size; i++) {
    if(arr[position] == 0) return false;
    visited.insert(position);
    position += arr[position];
    position = position % arr_size;
    if(position < 0) position += arr_size;
    if(position == 0) break;
  }
  if(i == arr_size) return false;

  int second_start = (*visited.cbegin());
  position = second_start;

  for(; i< arr_size; i++) {
    if(arr[position] == 0) return false;
    position += arr[position];
    position = position % arr_size;
    if(position < 0) position += arr_size;
    if(position == second_start && i != arr_size - 1) return false;
  }
  return position == second_start;
}

int main(int argc, char** argv) {
  int arr[] = { 2, 2, 2, 3, 1};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  auto result = is_double_array_cycle(arr, arr_size);
  std::cout << "An array " << (result ? "is": "is not") << " a double relative indices cycle\n";

  return 0;
}
