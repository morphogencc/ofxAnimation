#include "EasingFunction.h"
#include "easing_functions\Back.h"
#include "easing_functions\Bounce.h"
#include "easing_functions\Circ.h"
#include "easing_functions\Cubic.h"
#include "easing_functions\Elastic.h"
#include "easing_functions\Expo.h"
#include "easing_functions\Linear.h"
#include "easing_functions\Quad.h"
#include "easing_functions\Quart.h"
#include "easing_functions\Quint.h"
#include "easing_functions\Sine.h"

using namespace ofxAnimation;

std::shared_ptr<EasingFunction> EasingFunction::make(EasingFunctionType function, EasingType type) {
	std::shared_ptr<EasingFunction> easingFunction(new EasingFunction(function, type));
	return easingFunction;
}

EasingFunction::~EasingFunction() {

}

float EasingFunction::getValue(float time, EasingParameters params) {
	//the enormous matrix of function types and easing types.  This is where the nitty gritty gets done.

	switch (mFunctionType) {
	case LINEAR:
		switch (mEasingType) {
		case EASE_IN:
			return Linear::easeIn(time, params);
			break;
		case EASE_OUT:
			return Linear::easeOut(time, params);
			break;
		case EASE_INOUT:
			return Linear::easeInOut(time, params);
			break;
		}
		break;

	case QUADRATIC:
		switch (mEasingType) {
		case EASE_IN:
			return Quad::easeIn(time, params);
			break;
		case EASE_OUT:
			return Quad::easeOut(time, params);
			break;
		case EASE_INOUT:
			return Quad::easeInOut(time, params);
			break;
		}
		break;

	case CUBIC:
		switch (mEasingType) {
		case EASE_IN:
			return Cubic::easeIn(time, params);
			break;
		case EASE_OUT:
			return Cubic::easeOut(time, params);
			break;
		case EASE_INOUT:
			return Cubic::easeInOut(time, params);
			break;
		}
		break;

	case QUARTIC:
		switch (mEasingType) {
		case EASE_IN:
			return Quart::easeIn(time, params);
			break;
		case EASE_OUT:
			return Quart::easeOut(time, params);
			break;
		case EASE_INOUT:
			return Quart::easeInOut(time, params);
			break;
		}
		break;

	case QUINTIC:
		switch (mEasingType) {
		case EASE_IN:
			return Quint::easeIn(time, params);
			break;
		case EASE_OUT:
			return Quint::easeOut(time, params);
			break;
		case EASE_INOUT:
			return Quint::easeInOut(time, params);
			break;
		}
		break;

	case CIRCULAR:
		switch (mEasingType) {
		case EASE_IN:
			return Circ::easeIn(time, params);
			break;
		case EASE_OUT:
			return Circ::easeOut(time, params);
			break;
		case EASE_INOUT:
			return Circ::easeInOut(time, params);
			break;
		}
		break;

	case SINE:
		switch (mEasingType) {
		case EASE_IN:
			return Sine::easeIn(time, params);
			break;
		case EASE_OUT:
			return Sine::easeOut(time, params);
			break;
		case EASE_INOUT:
			return Sine::easeInOut(time, params);
			break;
		}
		break;

	case BACK:
		switch (mEasingType) {
		case EASE_IN:
			return Back::easeIn(time, params);
			break;
		case EASE_OUT:
			return Back::easeOut(time, params);
			break;
		case EASE_INOUT:
			return Back::easeInOut(time, params);
			break;
		}
		break;

	case EXPONENTIAL:
		switch (mEasingType) {
		case EASE_IN:
			return Expo::easeIn(time, params);
			break;
		case EASE_OUT:
			return Expo::easeOut(time, params);
			break;
		case EASE_INOUT:
			return Expo::easeInOut(time, params);
			break;
		}
		break;

	case ELASTIC:
		switch (mEasingType) {
		case EASE_IN:
			return Elastic::easeIn(time, params);
			break;
		case EASE_OUT:
			return Elastic::easeOut(time, params);
			break;
		case EASE_INOUT:
			return Elastic::easeInOut(time, params);
			break;
		}
		break;

	case BOUNCE:
		switch (mEasingType) {
		case EASE_IN:
			return Bounce::easeIn(time, params);
			break;
		case EASE_OUT:
			return Bounce::easeOut(time, params);
			break;
		case EASE_INOUT:
			return Bounce::easeInOut(time, params);
			break;
		}
		break;
	}

}

EasingFunction::EasingFunction(EasingFunctionType function, EasingType type) {
	mFunctionType = function;
	mEasingType = type;
}