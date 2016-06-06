#include "PointAnimation.h"

using namespace ofxAnimation;

PointAnimation::PointAnimation(ofPoint* target, ofPoint startValue, ofPoint endValue, std::chrono::time_point<std::chrono::system_clock> startTime, std::chrono::time_point<std::chrono::system_clock> endTime, std::shared_ptr<EasingFunction> easingFunction) {
    mTarget = target;
    mStartValue = startValue;
    mEndValue = endValue;
    mStartTime = startTime;
    mEndTime = endTime;
    mEasingFunction = easingFunction;
    for(int i = 0; i < 3; i++) {
        EasingParameters params;
        params.b = startValue[i];
        params.c = endValue[i] - startValue[i];
        params.d = std::chrono::duration_cast<std::chrono::milliseconds>(mEndTime - mStartTime).count();
        mEasingParameters.push_back(params);
    }
}

PointAnimation::~PointAnimation() {
    
}

void PointAnimation::update() {
    float currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - mStartTime).count();
    
    ofPoint newValue;
    for(int i = 0; i < 3; i++) {
        newValue[i] = mEasingFunction->getValue(currentTime, mEasingParameters[i]);
        std::printf("Point: %f", newValue[i]);
    }
    
    *mTarget = newValue;
    
    for (auto callback : mOnUpdateCallbacks) {
        callback(this);
    }
}

void PointAnimation::onCompletion() {
    for (auto callback : mOnCompletionCallbacks) {
        callback(this);
    }
}

bool PointAnimation::isFinished() {
    std::chrono::time_point<std::chrono::system_clock> currentTime = std::chrono::system_clock::now();
    if (currentTime > mEndTime) {
        return true;
    }
    else {
        return false;
    }
}

void PointAnimation::addUpdateCallback(std::function<void(PointAnimation*)> callback_function) {
    mOnUpdateCallbacks.push_back(callback_function);
}

void PointAnimation::addCompletionCallback(std::function<void(PointAnimation*)> callback_function) {
    mOnCompletionCallbacks.push_back(callback_function);
}