#include "Quad.h"

using namespace ofxAnimation;

float Quad::easeIn (float t, EasingParameters parameters) {
	return parameters.c*(t/=parameters.d)*t + parameters.b;
}
float Quad::easeOut(float t, EasingParameters parameters) {
	return -parameters.c *(t/=parameters.d)*(t-2) + parameters.b;
}

float Quad::easeInOut(float t, EasingParameters parameters) {
	if ((t/=parameters.d/2) < 1) return ((parameters.c/2)*(t*t)) + parameters.b;
	return -parameters.c/2 * (((t-2)*(--t)) - 1) + parameters.b;
	/*
	originally return -parameters.c/2 * (((t-2)*(--t)) - 1) + parameters.b;
	
	I've had to swap (--t)*(t-2) due to diffence in behaviour in 
	pre-increment operators between java and c++, after hours
	of joy
	*/	
}