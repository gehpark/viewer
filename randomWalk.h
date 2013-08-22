/*
 * Random Walk adjustable parameters
 */ 

// Time between updates, in milliseconds
#define TIMER_INTERVAL 	100.00

// Diffusitivity = (WALK_DIST)^2/(2 * TIMER_INTERVAL)
// In discrete mode, there can be two different diffisitivities for x and y direcitons.
#define WALK_DIST		.02

#define PARTICLE_RADIUS .01

#define WIND_ANGLE 3.1415926535
