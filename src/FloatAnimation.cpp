#include "FloatAnimation.h"

using namespace ofxAnimation;

FloatAnimation::FloatAnimation(float* target, float startValue, float endValue, std::chrono::time_point<std::chrono::system_clock> startTime, std::chrono::time_point<std::chrono::system_clock> endTime, std::shared_ptr<EasingFunction> easingFunction) {
	mTarget = target;
	mStartValue = startValue;
	mEndValue = endValue;
	mStartTime = startTime;
	mEndTime = endTime;
	mEasingFunction = easingFunction;
	mEasingParameters.b = startValue;
	mEasingParameters.c = endValue - startValue;
	mEasingParameters.d = std::chrono::duration_cast<std::chrono::milliseconds>(mEndTime - mStartTime).count();
}

FloatAnimation::~FloatAnimation() {

}

void FloatAnimation::update() {
	float currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - mStartTime).count();
	float newValue = mEasingFunction->getValue(currentTime, mEasingParameters);
	*mTarget = newValue;
	for (auto callback : mOnUpdateCallbacks) {
		callback(this);
	}
}

void FloatAnimation::onCompletion() {
	for (auto callback : mOnCompletionCallbacks) {
		callback(this);
	}
}

bool FloatAnimation::isFinished() {
	std::chrono::time_point<std::chrono::system_clock> currentTime = std::chrono::system_clock::now();
	if (currentTime > mEndTime) {
		return true;
	}
	else {
		return false;
	}
}

void FloatAnimation::addUpdateCallback(std::function<void(FloatAnimation*)> callback_function) {
	mOnUpdateCallbacks.push_back(callback_function);
}

void FloatAnimation::addCompletionCallback(std::function<void(FloatAnimation*)> callback_function) {
	mOnCompletionCallbacks.push_back(callback_function);
}