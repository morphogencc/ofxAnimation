#pragma once 

#include <memory>
#define PI 3.14159265

// http://gizma.com/easing/

namespace ofxAnimation {
	enum EasingType {
		EASE_IN,
		EASE_OUT,
		EASE_INOUT
	};

	enum EasingFunctionType {
		LINEAR,
		QUADRATIC,
		CUBIC,
		QUARTIC,
		QUINTIC,
		CIRCULAR,
		SINE,
		BACK,
		EXPONENTIAL,
		ELASTIC,
		BOUNCE
	};

	struct EasingParameters {
		float b;
		float c;
		float d;
	};

	class EasingFunction {
	public:
		static std::shared_ptr<EasingFunction> make(EasingFunctionType function, EasingType type);
		~EasingFunction();
		float getValue(float time, EasingParameters params);
	protected:
		EasingFunctionType mFunctionType;
		EasingType mEasingType;
	private:
		EasingFunction(EasingFunctionType function, EasingType type);
	};
}