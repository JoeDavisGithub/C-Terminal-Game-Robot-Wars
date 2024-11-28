#ifndef POINT_H
#define POINT_H

#include <string>

class point {
	int x;
	int y;
public:
	point(int ix, int iy);

	int getx() const {return x;}
	void setx(int nx) {
		x = nx;
	}
	void sety(int ny) {
		y = ny;
	}

	int gety() const {return y;}

	int dist();

	std::string show_point(const point& p);
};


#endif
