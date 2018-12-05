#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using IntVec = std::vector<int>;
auto find_intersection(const IntVec& a, const IntVec& b, const IntVec& c) {
  IntVec result;

  int i{0}, j{0}, k{0};
  while(!(i >= a.size() || j >= b.size() || k >= c.size())) {
    if(a[i] == b[j] && b[j] == c[k]) {
      result.push_back(a[i]); 
      i++; j++; k++;
      continue;
    }
    if(a[i] < b[j]) {
      i++;
    } else if(b[j] < c[k]) {
      j++;
    } else {
      k++;
    }
  } 

  return result;
} 

auto find_intersection_map(const IntVec& a, const IntVec& b, const IntVec& c) {
  IntVec result;
  std::map<int, int[3]> helper;

  for(const auto& item: a) {
    helper[item][0]++;
  }

  for(const auto& item: b) {
    helper[item][1]++;
  }

  for(const auto& item: c) {
    helper[item][2]++;
  }

  for(const auto& item: helper) {
    const auto least_items = std::min({item.second[0], item.second[1], item.second[2]});
    for(auto i = 0; i< least_items; i++) {
      result.push_back(item.first); 
    }
  }

  return result;
}

int main(int argc, char** argv) {
  IntVec a = {2,6,6,9,11,13,17};
  IntVec b = {3,6,6,7,10,13,18};
  IntVec c = {4,5,6,6,9,11,13};

  std::cout << "[";
  for(const auto& item: find_intersection_map(a, b, c)) {
    std::cout << item << " ";
  }
  std::cout << "]\n";

  return 0;
}
