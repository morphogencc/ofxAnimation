#pragma once

#include <chrono>
#include <memory>
#include <vector>
#include <thread>
#include "Animation.h"
#include "EasingFunction.h"

namespace ofxAnimation {
    
    class FloatAnimation : public Animation {
    public:
        FloatAnimation(float* target, float startValue, float endValue, std::chrono::time_point<std::chrono::system_clock> startTime, std::chrono::time_point<std::chrono::system_clock> endTime, std::shared_ptr<EasingFunction> easingFunction);
        ~FloatAnimation();
        void update();
        void onCompletion();
        bool isFinished();
        void addUpdateCallback(std::function<void(FloatAnimation*)> callback_function);
        void addCompletionCallback(std::function<void(FloatAnimation*)> callback_function);
    protected:
        float* mTarget;
        float mStartValue;
        float mEndValue;
        EasingParameters mEasingParameters;
        std::vector<std::function<void(FloatAnimation*)> >  mOnUpdateCallbacks;
        std::vector<std::function<void(FloatAnimation*)> >  mOnCompletionCallbacks;
    };
}