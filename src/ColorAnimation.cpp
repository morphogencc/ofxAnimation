#include "ColorAnimation.h"

using namespace ofxAnimation;

ColorAnimation::ColorAnimation(ofColor* target, ofColor startValue, ofColor endValue, std::chrono::time_point<std::chrono::system_clock> startTime, std::chrono::time_point<std::chrono::system_clock> endTime, std::shared_ptr<EasingFunction> easingFunction) {
    mTarget = target;
    mStartValue = startValue;
    mEndValue = endValue;
    mStartTime = startTime;
    mEndTime = endTime;
    mEasingFunction = easingFunction;
    for(int i = 0; i < 4; i++) {
        EasingParameters params;
        params.b = startValue[i];
        params.c = endValue[i] - startValue[i];
        params.d = std::chrono::duration_cast<std::chrono::milliseconds>(mEndTime - mStartTime).count();
        mEasingParameters.push_back(params);
    }
}

ColorAnimation::~ColorAnimation() {
    
}

void ColorAnimation::update() {
    float currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - mStartTime).count();
    
    ofColor newValue;
    for(int i = 0; i < 4; i++) {
        newValue[i] = mEasingFunction->getValue(currentTime, mEasingParameters[i]);
    }
    *mTarget = newValue;
    
    for (auto callback : mOnUpdateCallbacks) {
        callback(this);
    }
}

void ColorAnimation::onCompletion() {
    for (auto callback : mOnCompletionCallbacks) {
        callback(this);
    }
}

bool ColorAnimation::isFinished() {
    std::chrono::time_point<std::chrono::system_clock> currentTime = std::chrono::system_clock::now();
    if (currentTime > mEndTime) {
        return true;
    }
    else {
        return false;
    }
}

void ColorAnimation::addUpdateCallback(std::function<void(ColorAnimation*)> callback_function) {
    mOnUpdateCallbacks.push_back(callback_function);
}

void ColorAnimation::addCompletionCallback(std::function<void(ColorAnimation*)> callback_function) {
    mOnCompletionCallbacks.push_back(callback_function);
}