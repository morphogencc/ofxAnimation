#include "Expo.h"

using namespace ofxAnimation;

float Expo::easeIn (float t, EasingParameters parameters) {
	return (t==0) ? parameters.b : parameters.c * pow(2, 10 * (t/parameters.d - 1)) + parameters.b;
}
float Expo::easeOut(float t, EasingParameters parameters) {
	return (t==parameters.d) ? parameters.b +parameters.c : parameters.c * (-pow(2, -10 * t/parameters.d) + 1) + parameters.b;	
}

float Expo::easeInOut(float t, EasingParameters parameters) {
	if (t==0) return parameters.b;
	if (t==parameters.d) return parameters.b +parameters.c;
	if ((t/=parameters.d/2) < 1) return parameters.c/2 * pow(2, 10 * (t - 1)) + parameters.b;
	return parameters.c/2 * (-pow(2, -10 * --t) + 2) + parameters.b;
}