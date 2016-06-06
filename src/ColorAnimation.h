#pragma once

#include <chrono>
#include <memory>
#include <vector>
#include <thread>
#include "ofMain.h"
#include "Animation.h"
#include "EasingFunction.h"

namespace ofxAnimation {
    
    class ColorAnimation : public Animation {
    public:
        ColorAnimation(ofColor* target, ofColor startValue, ofColor endValue, std::chrono::time_point<std::chrono::system_clock> startTime, std::chrono::time_point<std::chrono::system_clock> endTime, std::shared_ptr<EasingFunction> easingFunction);
        ~ColorAnimation();
        void update();
        void onCompletion();
        bool isFinished();
        void addUpdateCallback(std::function<void(ColorAnimation*)> callback_function);
        void addCompletionCallback(std::function<void(ColorAnimation*)> callback_function);
    protected:
        ofColor* mTarget;
        ofColor mStartValue;
        ofColor mEndValue;
        std::vector<EasingParameters> mEasingParameters;
        std::vector<std::function<void(ColorAnimation*)> >  mOnUpdateCallbacks;
        std::vector<std::function<void(ColorAnimation*)> >  mOnCompletionCallbacks;
        
    };
}