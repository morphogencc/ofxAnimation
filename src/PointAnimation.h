#pragma once

#include <chrono>
#include <memory>
#include <vector>
#include <thread>
#include "ofMain.h"
#include "Animation.h"
#include "EasingFunction.h"

namespace ofxAnimation {
    
    class PointAnimation : public Animation {
    public:
        PointAnimation(ofPoint* target, ofPoint startValue, ofPoint endValue, std::chrono::time_point<std::chrono::system_clock> startTime, std::chrono::time_point<std::chrono::system_clock> endTime, std::shared_ptr<EasingFunction> easingFunction);
        ~PointAnimation();
        void update();
        void onCompletion();
        bool isFinished();
        void addUpdateCallback(std::function<void(PointAnimation*)> callback_function);
        void addCompletionCallback(std::function<void(PointAnimation*)> callback_function);
    protected:
        ofPoint* mTarget;
        ofPoint mStartValue;
        ofPoint mEndValue;
        std::vector<EasingParameters> mEasingParameters;
        std::vector<std::function<void(PointAnimation*)> >  mOnUpdateCallbacks;
        std::vector<std::function<void(PointAnimation*)> >  mOnCompletionCallbacks;
        
    };
}