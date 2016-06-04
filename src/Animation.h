#pragma once 

#include <chrono>
#include <memory>
#include <vector>
#include <thread>
#include "EasingFunction.h"

namespace ofxAnimation {

	class Animation {
	public:
		Animation(float* target, float startValue, float endValue, std::chrono::time_point<std::chrono::system_clock> startTime, std::chrono::time_point<std::chrono::system_clock> endTime, std::shared_ptr<EasingFunction> easingFunction);
		~Animation();
		void update();
		void onCompletion();
		bool isFinished();
		void addUpdateCallback(std::function<void(Animation*)> callback_function);
		void addCompletionCallback(std::function<void(Animation*)> callback_function);
	protected:
		float* mTarget;
		//ofPoint* mPointTarget;
		//ofColor* mColorTarget;
		float mStartValue;
		float mEndValue;
		std::chrono::time_point<std::chrono::system_clock> mStartTime;
		std::chrono::time_point<std::chrono::system_clock> mEndTime;
		//int mStartFrame;
		//int mEndFrame;
		std::shared_ptr<EasingFunction> mEasingFunction;
		EasingParameters mEasingParameters;
		std::vector<std::function<void(Animation*)> >  mOnUpdateCallbacks;
		std::vector<std::function<void(Animation*)> >  mOnCompletionCallbacks;

	};
}