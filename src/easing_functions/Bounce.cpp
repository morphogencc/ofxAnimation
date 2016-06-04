#include "Bounce.h"

using namespace ofxAnimation;

float Bounce::easeIn (float t, EasingParameters parameters) {
	EasingParameters newParameters;
	newParameters.b = 0;
	newParameters.c = parameters.c;
	newParameters.d = parameters.d;

	return parameters.c - easeOut(parameters.d-t, newParameters) + parameters.b;
}
float Bounce::easeOut(float t, EasingParameters parameters) {
	if ((t/=parameters.d) < (1/2.75f)) {
		return parameters.c*(7.5625f*t*t) + parameters.b;
	} else if (t < (2/2.75f)) {
		float postFix = t-=(1.5f/2.75f);
		return parameters.c*(7.5625f*(postFix)*t + .75f) + parameters.b;
	} else if (t < (2.5/2.75)) {
			float postFix = t-=(2.25f/2.75f);
		return parameters.c*(7.5625f*(postFix)*t + .9375f) + parameters.b;
	} else {
		float postFix = t-=(2.625f/2.75f);
		return parameters.c*(7.5625f*(postFix)*t + .984375f) + parameters.b;
	}
}

float Bounce::easeInOut(float t, EasingParameters parameters) {
	EasingParameters newParameters;
	newParameters.b = 0;
	newParameters.c = parameters.c;
	newParameters.d = parameters.d;

	if (t < parameters.d/2) return easeIn (t*2, newParameters) * .5f + parameters.b;
	else return easeOut (t*2-parameters.d, newParameters) * .5f + parameters.c*.5f + parameters.b;
}