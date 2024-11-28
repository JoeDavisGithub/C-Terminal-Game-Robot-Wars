#include "point.h"
#include <cmath>
#include <string>

using namespace std;

point::point(int ix, int iy) :
	x(ix), y(iy) {}

int point::dist() {
	return abs(x) + abs(y);
}

string point::show_point(const point& p) {
	return "(" + std::to_string(p.getx()) + ", " + std::to_string(p.gety()) + ")";
}
