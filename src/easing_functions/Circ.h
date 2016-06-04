#include "EasingFunction.h"
#include <math.h>

namespace ofxAnimation {

	class Circ {

	public:

		static float easeIn(float t, EasingParameters parameters);
		static float easeOut(float t, EasingParameters parameters);
		static float easeInOut(float t, EasingParameters parameters);
	};

}