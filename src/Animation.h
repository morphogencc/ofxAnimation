#pragma once

#include <chrono>
#include <memory>
#include <vector>
#include <thread>
#include "EasingFunction.h"

namespace ofxAnimation {
    
    class Animation {
    public:
        Animation() {};
        ~Animation() {};
        virtual void update() = 0;
        virtual void onCompletion() = 0;
        virtual bool isFinished() = 0;
    protected:
        std::chrono::time_point<std::chrono::system_clock> mStartTime;
        std::chrono::time_point<std::chrono::system_clock> mEndTime;
        //int mStartFrame;
        //int mEndFrame;
        std::shared_ptr<EasingFunction> mEasingFunction;
    };
}