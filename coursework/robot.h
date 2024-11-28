#ifndef ROBOT_H
#define ROBOT_H
#include "point.h"
#include <string>
#include <cmath>

class robot {
	std::string direction;
	int name;
	int team;
	int travelled;
	point locale;
public:
	robot(int n,int t, point loc);

	void turnleft();

	void turnright();

	void move();

	std::string getdirection() {
		return direction;
	}
	int getname() {
		return name;
	}
	int getteam() {
		return team;
	}
	int gettravelled() {
		return travelled;
	}
	void inctravelled() {
		++travelled;
	}
	point getpoint() {
		return locale;
	}

	~robot() {}
};

#endif