#include "Linear.h"

using namespace ofxAnimation;

float Linear::easeIn (float t, EasingParameters parameters) {
	return parameters.c*t/parameters.d + parameters.b;
}
float Linear::easeOut(float t, EasingParameters parameters) {
	return parameters.c*t/ parameters.d + parameters.b;
}

float Linear::easeInOut(float t, EasingParameters parameters) {
	return parameters.c*t/ parameters.d + parameters.b;
}