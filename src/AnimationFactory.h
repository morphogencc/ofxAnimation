#pragma once 

#include <deque>
#include <memory>
#include <chrono>
#include "Animation.h"
#include "FloatAnimation.h"
#include "ColorAnimation.h"
#include "PointAnimation.h"
#include "EasingFunction.h"
#include "ofMain.h"

namespace ofxAnimation {
	class AnimationFactory {
	public:
		static std::shared_ptr<AnimationFactory> getInstance();
		std::shared_ptr<FloatAnimation> addAnimation(float* target, float endValue, int durationInMilliseconds, std::shared_ptr<EasingFunction> easingFunction);
		std::shared_ptr<ColorAnimation> addAnimation(ofColor* target, ofColor endValue, int durationInMilliseconds, std::shared_ptr<EasingFunction> easingFunction);
		std::shared_ptr<PointAnimation> addAnimation(ofPoint* target, ofPoint endValue, int durationInMilliseconds, std::shared_ptr<EasingFunction> easingFunction);
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
