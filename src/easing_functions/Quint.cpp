#include "Quint.h"

using namespace ofxAnimation;

float Quint::easeIn (float t, EasingParameters parameters) {
	return parameters.c*(t/=parameters.d)*t*t*t*t + parameters.b;
}
float Quint::easeOut(float t, EasingParameters parameters) {
	return parameters.c*((t=t/parameters.d-1)*t*t*t*t + 1) + parameters.b;
}

float Quint::easeInOut(float t, EasingParameters parameters) {
	if ((t/=parameters.d/2) < 1) return parameters.c/2*t*t*t*t*t + parameters.b;
	return parameters.c/2*((t-=2)*t*t*t*t + 2) + parameters.b;
}