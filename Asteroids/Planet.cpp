#include "Planet.h"



Planet::Planet()
{
}

Planet::Planet(std::string _name, double _m1, double _m2, double _m3, double _m4, double _m5, double _pirates, sf::IntRect _location)
{
	active = false;
	mineral[0] = _m1;
	mineral[1] = _m2;
	mineral[2] = _m3;
	mineral[3] = _m4;
	mineral[4] = _m5;
	pirates = _pirates;
	name = _name;
	location = _location;
}

Planet::~Planet()
{
}
