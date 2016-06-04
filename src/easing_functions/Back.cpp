#include "Back.h"

using namespace ofxAnimation;

float Back::easeIn (float t, EasingParameters parameters) {
	float s = 1.70158f;
	float postFix = t/=parameters.d;
	return parameters.c*(postFix)*t*((s+1)*t - s) + parameters.b;
}
float Back::easeOut(float t, EasingParameters parameters) {	
	float s = 1.70158f;
	return parameters.c*((t=t/parameters.d-1)*t*((s+1)*t + s) + 1) + parameters.b;
}

float Back::easeInOut(float t, EasingParameters parameters) {
	float s = 1.70158f;
	if ((t/=parameters.d/2) < 1) return parameters.c/2*(t*t*(((s*=(1.525f))+1)*t - s)) + parameters.b;
	float postFix = t-=2;
	return parameters.c/2*((postFix)*t*(((s*=(1.525f))+1)*t + s) + 2) + parameters.b;
}