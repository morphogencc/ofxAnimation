#pragma once 

#include <deque>
#include <memory>
#include <chrono>
#include "Animation.h"
#include "EasingFunction.h"
#include "ofMain.h"

namespace ofxAnimation {
	class AnimationFactory {
	public:
		static std::shared_ptr<AnimationFactory> getInstance();
		std::shared_ptr<Animation> addAnimation(float* target, float endValue, int durationInMilliseconds, std::shared_ptr<EasingFunction> easingFunction);
		//std::shared_ptr<Animation> addAnimation(ofColor& target, float endValue, float durationInSeconds, std::shared_ptr<EasingFunction> easingFunction);
		//std::shared_ptr<Animation> addAnimation(ofPoint& target, float endValue, float durationInSeconds, std::shared_ptr<EasingFunction> easingFunction);
		//std::shared_ptr<Animation> addAnimation(float& target, float startValue, float endValue, float durationInSeconds, std::shared_ptr<EasingFunction> easingFunction);
		//std::shared_ptr<Animation> addAnimation(float& target, float startValue, float endValue, float start, std::shared_ptr<EasingFunction> easingFunction);
		void update();
		//void setFrameSequencing(bool frameSequencing);
		int getNumberOfAnimations();
	protected:
		static std::shared_ptr<AnimationFactory> mAnimationFactory;
		std::deque<std::shared_ptr<Animation> > mAnimations;
	private:
		AnimationFactory();
	};

}
