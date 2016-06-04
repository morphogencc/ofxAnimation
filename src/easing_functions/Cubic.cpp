#include "Cubic.h"

using namespace ofxAnimation;

float Cubic::easeIn (float t, EasingParameters parameters) {
	return parameters.c*(t/=parameters.d)*t*t + parameters.b;
}
float Cubic::easeOut(float t, EasingParameters parameters) {
	return parameters.c*((t=t/parameters.d-1)*t*t + 1) + parameters.b;
}

float Cubic::easeInOut(float t, EasingParameters parameters) {
	if ((t/=parameters.d/2) < 1) return parameters.c/2*t*t*t + parameters.b;
	return parameters.c/2*((t-=2)*t*t + 2) + parameters.b;	
}