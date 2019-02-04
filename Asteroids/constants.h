#ifndef CONSTANTS_H
#define CONSTANTS_H
const float SLOW_FRICTION = 0.995f;
const float FAST_FRICTION = 0.98f;

const int NO_MINERALS = 5;
const int MAX_PLANETS = 9;

#define PI_F 3.14159265358979f


enum class
	EngineState {
	Drift,
	Power,
	Turn
};



#endif  //CONSTANTS_H