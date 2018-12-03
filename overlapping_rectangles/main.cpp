#include <iostream>

struct Point {
  Point(int x, int y): X(x), Y(y) {
  }

  int X;
  int Y;
};

enum class Orientation {
  HORIZONTAL,
  VERTICAL
};

struct Edge {

  Edge(const Point& p1, const Point& p2):
    start(p1),
    end(p2) {
    if(p1.X == p2.X) orientation = Orientation::HORIZONTAL;
    else if(p1.Y == p2.Y) orientation = Orientation::VERTICAL;
  }
  Point start;
  Point end;
  Orientation orientation;
};

struct Rectangle {
  Rectangle(Point bl, Point tr):
    bottom_left(bl),
    top_right(tr) {
  }

  Point bottom_left; 
  Point top_right;

  Edge get_bottom_edge() {
    return Edge(bottom_left, Point{top_right.X, bottom_left.Y});
  }

  Edge get_top_edge() {
    return Edge(Point{bottom_left.X, top_right.Y}, top_right);
  }

  Edge get_left_edge() {
    int x = bottom_left.X;
    return Edge(Point{x, bottom_left.Y}, Point{x, top_right.Y});
  }
  Edge get_right_edge() {
    int x = top_right.X;
    return Edge(Point{x, bottom_left.Y}, Point{x, top_right.Y});
  }
};

Point cutting_edges(const Edge& e1, const Edge& e2) {
  if(e1.orientation == e2.orientation) {
    if(e1.orientation == Orientation.HORIZONTAL) {
      if(e1.start.X <= e2.start.X && e1.end.X >= e2.start.X
      || e2.start.X <= e1.start.Y && e2.end.X >= e1.start.X) {
        return Point{ 
      }
    }
  }
  return true;
}

int overlapping_area(const Rectangle& r1, const Rectangle& r2) {
  
}

int main(int argc, char** argv) {
  
  return 0;
}
