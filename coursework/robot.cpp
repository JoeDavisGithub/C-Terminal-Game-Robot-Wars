#include "robot.h"
#include <string>
using namespace std;



robot::robot(int n, int t, point loc) :
	direction("north"), name(n),team(t), locale(loc), travelled(0) {}

void robot::turnleft(){
	if (direction == "north")
		direction = "west";
	else if (direction == "west")
		direction = "south";
	else if (direction == "south")
		direction = "east";
	else if (direction == "east")
		direction = "north";
}

void robot::turnright(){
	if (direction == "north")
		direction = "east";
	else if (direction == "east")
		direction = "south";
	else if (direction == "south")
		direction = "west";
	else if (direction == "west")
		direction = "north";
}

void robot::move() {
	if (direction == "north")
		locale.sety(locale.gety() + 1);
	else if (direction == "west")
		locale.setx(locale.getx() - 1);
	else if (direction == "south")
		locale.sety(locale.gety() - 1);
	else if (direction == "east")
		locale.setx(locale.getx() + 1);
}



