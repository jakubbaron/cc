#include <iostream>
#include <vector>

int find_next_denom(double fraction, int in_denom) {
  double temp = 1.0 / in_denom;
  if(temp < fraction) return in_denom;
  int last_denom{in_denom};
  while (temp > fraction) {
    last_denom = in_denom;
    in_denom *= 2;
    temp = 1.0 / in_denom;
  }
  std::cout << "Found range[" << last_denom << "][" << in_denom << "]\n";
  //at this point we know the range, that the sought denom is 
  //between last_denom and in_denom

  int mid{(in_denom + last_denom) / 2};
  int last_mid = mid;
  while(true) {
    last_mid = mid;
    mid = (in_denom + last_denom) / 2;
    if((in_denom + last_denom) % 2 != 0)  mid += 1;
    temp = 1.0 / mid;
    if(temp > fraction) {
      last_denom = mid;
    }
    if(temp < fraction) {
      in_denom = mid;
    }
    
    if(in_denom - last_denom == 1) return std::max(last_denom, in_denom);
  }
}

void find_numerators(int in_num, int in_denom) {
  if(in_num > in_denom) return; 

  int denom{2};
  double fraction{(in_num + 0.0)/in_denom};
  std::vector<int> results;
  while(fraction > 0.000001) {
    denom = find_next_denom(fraction, denom);
    std::cout << "Fraction works[" << denom << "]\n";
    results.push_back(denom);
    fraction -= (1.0/denom);
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
