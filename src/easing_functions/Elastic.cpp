#include "Elastic.h"

using namespace ofxAnimation;

float Elastic::easeIn (float t, EasingParameters parameters) {
	if (t==0) return parameters.b;  if ((t/=parameters.d)==1) return parameters.b + parameters.c;  
	float p=parameters.d*.3f;
	float a=parameters.c; 
	float s=p/4;
	float postFix =a*pow(2,10*(t-=1)); // this is a fix, again, with post-increment operators
	return -(postFix * sin((t*parameters.d-s)*(2*PI)/p )) + parameters.b;
}

float Elastic::easeOut(float t, EasingParameters parameters) {
	if (t==0) return parameters.b;  if ((t/=parameters.d)==1) return parameters.b + parameters.c;  
	float p=parameters.d*.3f;
	float a=parameters.c; 
	float s=p/4;
	return (a*pow(2,-10*t) * sin( (t*parameters.d-s)*(2*PI)/p ) + parameters.c + parameters.b);	
}

float Elastic::easeInOut(float t, EasingParameters parameters) {
	if (t==0) return parameters.b;  if ((t/=parameters.d/2)==2) return parameters.b + parameters.c; 
	float p=parameters.d*(.3f*1.5f);
	float a=parameters.c; 
	float s=p/4;
	 
	if (t < 1) {
		float postFix =a*pow(2,10*(t-=1)); // postIncrement is evil
		return -.5f*(postFix* sin( (t*parameters.d-s)*(2*PI)/p )) + parameters.b;
	} 
	float postFix =  a*pow(2,-10*(t-=1)); // postIncrement is evil
	return postFix * sin( (t*parameters.d-s)*(2*PI)/p )*.5f + parameters.c + parameters.b;
}