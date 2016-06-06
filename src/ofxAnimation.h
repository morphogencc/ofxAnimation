#pragma once 

#include "EasingFunction.h"
#include "AnimationFactory.h"
#include "FloatAnimation.h"
#include "ColorAnimation.h"
#include "PointAnimation.h"

/****************************************
ofxAnimation.h

To use this library, include this file.

the two objects the user deals with are:

* AnimationFactory.h
* EasingFunction.h

Create an instance of AnimationFactory:

std::shared_ptr<AnimationFactory> factory = AnimationFactory::getInstance();

You can call this function in any class with AnimationFactory.h included to call the factory.

If you'd like to create an animation, then select an easing function:

std::shared_ptr<EasingFunction> myEasingFunction = EasingFunction::make(QUADRATIC, EASE_IN, 0.25, 0.5, 0.33);

and then create an animation:

factory->addAnimation(myVariable, targetValue, 1.0, myEasingFunction);

the above will set the variable "myVariable" to transition to "targetValue" over 1.0 seconds, using myEasingFunction.

You can reuse the same easing function for multiple variables:

factory->addAnimation(myVariable, targetValue, 1.0, myEasingFunction);
factory->addAnimation(myOtherVariable, otherTargetValue, 5.0, myEasingFunction);
factory->addAnimation(myFinalVariable, finalTargetValue, 3.35, myEasingFunction);

All animations will automatically delete and clean themselves up.

****************************************/