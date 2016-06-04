#include "Sine.h"

using namespace ofxAnimation;

float Sine::easeIn (float t, EasingParameters parameters) {
	return -parameters.c * cos(t/parameters.d * (PI/2)) + parameters.c + parameters.b;
}
float Sine::easeOut(float t, EasingParameters parameters) {	
	return parameters.c * sin(t/parameters.d * (PI/2)) + parameters.b;	
}

float Sine::easeInOut(float t, EasingParameters parameters) {
	return -parameters.c/2 * (cos(PI*t/parameters.d) - 1) + parameters.b;
}