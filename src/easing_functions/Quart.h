#include "EasingFunction.h"

namespace ofxAnimation {

	class Quart {

	public:

		static float easeIn(float t, EasingParameters parameters);
		static float easeOut(float t, EasingParameters parameters);
		static float easeInOut(float t, EasingParameters parameters);
	};

}