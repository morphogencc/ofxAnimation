#include "Circ.h"

using namespace ofxAnimation;

float Circ::easeIn (float t, EasingParameters parameters) {
	return -parameters.c * (sqrt(1 - (t/=parameters.d)*t) - 1) + parameters.b;
}
float Circ::easeOut(float t, EasingParameters parameters) {
	return parameters.c * sqrt(1 - (t=t/parameters.d-1)*t) + parameters.b;
}

float Circ::easeInOut(float t, EasingParameters parameters) {
	if ((t/=parameters.d/2) < 1) return -parameters.c/2 * (sqrt(1 - t*t) - 1) + parameters.b;
	return parameters.c/2 * (sqrt(1 - t*(t-=2)) + 1) + parameters.b;
}