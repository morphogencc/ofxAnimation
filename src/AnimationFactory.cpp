#include "AnimationFactory.h"

using namespace ofxAnimation;

std::shared_ptr<AnimationFactory> AnimationFactory::mAnimationFactory = nullptr;

std::shared_ptr<AnimationFactory> AnimationFactory::getInstance() {
	if (mAnimationFactory == nullptr) {
		mAnimationFactory = std::shared_ptr<AnimationFactory>(new AnimationFactory());
	}
	return mAnimationFactory;
}

std::shared_ptr<Animation> AnimationFactory::addAnimation(float* target, float endValue, int durationInMilliseconds, std::shared_ptr<EasingFunction> easingFunction) {
	// NOTE TO SELF -- make sure that the math with std::chrono is working out okay here.
	std::chrono::time_point<std::chrono::system_clock> startTime = std::chrono::system_clock::now();
	std::chrono::time_point<std::chrono::system_clock> endTime = startTime + std::chrono::milliseconds(durationInMilliseconds);

	std::shared_ptr<Animation> animation = std::make_shared<Animation>(target, *target, endValue, startTime, endTime, easingFunction);
	mAnimations.push_back(animation);

	return animation;
}

void AnimationFactory::update() {
	std::chrono::time_point<std::chrono::system_clock> currentTime = std::chrono::system_clock::now();
	for (auto animation = mAnimations.begin(); animation != mAnimations.end();) {
		if ((*animation)->isFinished()) {
			(*animation)->onCompletion();
			animation = mAnimations.erase(animation);
		}
		else {
			(*animation)->update();
			++animation;
		}
	}
}

int AnimationFactory::getNumberOfAnimations() {
	return mAnimations.size();
}

AnimationFactory::AnimationFactory() {

}