#include "Quart.h"

using namespace ofxAnimation;

float Quart::easeIn (float t, EasingParameters parameters) {
	return parameters.c*(t/=parameters.d)*t*t*t + parameters.b;
}
float Quart::easeOut(float t, EasingParameters parameters) {
	return -parameters.c * ((t=t/parameters.d-1)*t*t*t - 1) + parameters.b;
}

float Quart::easeInOut(float t, EasingParameters parameters) {
	if ((t/=parameters.d/2) < 1) return parameters.c/2*t*t*t*t + parameters.b;
	return -parameters.c/2 * ((t-=2)*t*t*t - 2) + parameters.b;
}