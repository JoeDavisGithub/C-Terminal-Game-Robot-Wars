#include "robot.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> split_line(const string& s) {
	vector<string> v;
	auto space = find(s.cbegin(), s.cend(), ' ');
	v.push_back(string(s.cbegin(), space));
	while (space != s.cend()) {
		auto start = ++space;
		space = find(start, s.cend(), ' ');
		v.push_back(string(start, space));
	}
	return v;
}
bool showcomparisons(robot*& a, robot*& b) {
	return(a->getname() < b->getname());
}
bool travelcomparisons(robot* & a, robot* & b) {
	return(a->gettravelled() < b->gettravelled() || ((a->gettravelled() == b->gettravelled()) && (a->getname() < b->getname())));
}
void read_start(vector<robot*>& ac,const string & filename) {
	ifstream in(filename);
	string s;
	while (getline(in, s)) {
		vector<string> temp = split_line(s);
		ac.push_back(new robot(stoi(temp[0]),stoi(temp[1]),point(stoi(temp[2]), stoi(temp[3]))));
	}
}

void within(const vector<robot*>& ac, const int& n) {
	cout << n << '\n';
	int count = count_if(ac.cbegin(), ac.cend(), [n](robot* k) {return k->getpoint().dist() < n; });
	cout<< count<<'\n';
}
void const travellog(const vector<robot*>& ac) {
	for (robot* s : ac) {
		cout << s->getname() <<" "<< s->gettravelled()<< '\n';
	}
}
void const show(const vector<robot*>& ac) {
	for (robot* s : ac) {
		cout << s->getname() << " " << s->getteam() << " " << s->getpoint().getx() << " " << s->getpoint().gety() << '\n';
	}
}

void read_commands(vector<robot*>& ac, const string& filename) {
	ifstream in(filename);
	string s;
	while (getline(in, s)) {
		vector<string> temp = split_line(s);
		
		if (temp[0] == "show") {
			sort(ac.begin(), ac.end(), &showcomparisons);
			show(ac);
		}
		else if (temp[0] == "travelled")
		{
			sort(ac.begin(), ac.end(), &travelcomparisons);
			travellog(ac);
		}
		else if (temp[0] == "within")
		{
			within(ac,stoi(temp[1]));
		}
		else if (temp[0] == "turnleft"){
			for (robot* s : ac) {
				if (s->getname() == stoi(temp[1])) {
					s->turnleft();
					break;
				}
			}
		}
		else if (temp[0] == "turnright"){
			for (robot* s : ac) {
				if (s->getname() == stoi(temp[1])) {
					s->turnright();
					break;
				}
			}
		}
		else if (temp[0] == "move")
		{
			for (robot* s : ac) {
				if (s->getname() == stoi(temp[1])) {
					bool detecflag = false;
					for (robot* j : ac) {
						
						if (s->getdirection() == "north") {
							if ((j->getpoint().getx() == s->getpoint().getx()) && (j->getpoint().gety() - 1 == s->getpoint().gety()))
								if (j->getteam() != s->getteam()) {
									delete j;
									ac.erase(remove(ac.begin(), ac.end(), j), ac.end());
								}
								else if (j->getteam() == s->getteam()) {
									detecflag = true;
								}
									
						}
						else if (s->getdirection() == "east") {
							if ((j->getpoint().getx() -1 == s->getpoint().getx()) && (j->getpoint().gety() == s->getpoint().gety()))
								if (j->getteam() != s->getteam()) {
									delete j;
									ac.erase(remove(ac.begin(), ac.end(), j), ac.end());
								}
								else if (j->getteam() == s->getteam()) {
									detecflag = true;
								}
						}
						else if (s->getdirection() == "west") {
							if ((j->getpoint().getx() +1 == s->getpoint().getx()) && (j->getpoint().gety() == s->getpoint().gety()))
								if (j->getteam() != s->getteam()) {
									delete j;
									ac.erase(remove(ac.begin(), ac.end(), j), ac.end());
								}
								else if (j->getteam() == s->getteam()) {
									detecflag = true;
								}
									
						}
						else if (s->getdirection() == "south") {
							if ((j->getpoint().getx() == s->getpoint().getx()) && (j->getpoint().gety() + 1 == s->getpoint().gety()))
								if (j->getteam() != s->getteam()){
									delete j;
									ac.erase(remove(ac.begin(), ac.end(), j), ac.end());
								}
								else if (j->getteam() == s->getteam()) {
									detecflag = true;
								}
						}
					
					}
					if (detecflag == false) {
						s->move();
						s->inctravelled();
					}
					
				}
					
			}
		}

	}
}



int main() {
	vector<robot *> active;

	read_start(active,"start.txt");

	read_commands(active, "commands.txt");


	

	return 0;
}
