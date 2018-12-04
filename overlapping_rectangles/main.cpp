#include <iostream>
#include <algorithm>

struct Point {
  Point(int x, int y): X(x), Y(y) {
  }

  int X;
  int Y;
};

struct Rectangle {
  Rectangle(Point bl, Point tr):
    bottom_left(bl),
    top_right(tr) {
  }

  Point bottom_left; 
  Point top_right;
};

int overlapping_area(const Rectangle& r1, const Rectangle& r2) {
  int starting_x = std::max(r1.bottom_left.X, r2.bottom_left.X);
  int finish_x = std::min(r1.top_right.X, r2.top_right.X);
  int length_x = finish_x - starting_x;
  if(length_x < 0) return -1;

  int starting_y = std::max(r1.bottom_left.Y, r2.bottom_left.Y);
  int finish_y = std::min(r1.top_right.Y, r2.top_right.Y);
  int height_y = (finish_y - starting_y);
  if(height_y < 0) return -1;

  return length_x * height_y;
}

int main(int argc, char** argv) {
  Rectangle r1{Point{2,1}, Point{5,5}}; 
  Rectangle r2{Point{3,2}, Point{5,7}}; 
  std::cout << "Overlapping area: " << overlapping_area(r1, r2) << std::endl;

  return 0;
}
