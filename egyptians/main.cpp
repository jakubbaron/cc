#include <iostream>
#include <vector>

void find_numerators(int in_num, int in_denom) {
  if(in_num > in_denom) return; 

  int denom{2};
  double fraction{(in_num + 0.0)/in_denom};
  std::vector<int> results;
  while(fraction > 0.000001) {
    double temp = 1.0 / denom; 
    if(fraction - temp < 0) {
      denom++;
      continue;
    }
    std::cout << "Fraction works[" << denom << "]\n";
    results.push_back(denom);
    fraction -= temp;
  }

  std::cout << "Chosen fractions: ";
  for(const auto& item: results) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char** argv) {
  find_numerators(4, 13);
  return 0;
}
