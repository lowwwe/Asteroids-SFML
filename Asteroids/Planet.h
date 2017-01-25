#ifndef PLANET
#define PLANET
#include <string.h>
#include <SFML\Graphics.hpp>

class Planet
{
public:
	Planet();
	Planet::Planet(std::string _name, double _m1, double _m2, double _m3, double _m4, double _m5, double _pirates, sf::IntRect _location);
	~Planet();
public:
	bool active;
	double mineral[5];
	double pirates;
	std::string name;
	sf::IntRect location;	
};

#endif // !PLANET