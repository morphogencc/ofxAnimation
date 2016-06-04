# ofxAnimation.h

## Requirements
* C++11

## Usage
To use this library, include this file.

the two objects the user deals with are:

* `AnimationFactory.h`
* `EasingFunction.h`

Create an instance of AnimationFactory:

`std::shared_ptr<AnimationFactory> factory = AnimationFactory::getInstance();`

You can call this function in any class with AnimationFactory.h included to call the factory.

If you'd like to create an animation, then select an easing function:

`std::shared_ptr<EasingFunction> myEasingFunction = EasingFunction::make(QUADRATIC, EASE_IN);`

and then create an animation:

`factory->addAnimation(myVariable, targetValue, 1000, myEasingFunction);`

the above will set the variable "myVariable" to transition to "targetValue" over 1000 milliseconds (1 second), using myEasingFunction.

You can reuse the same easing function for multiple variables:

```
factory->addAnimation(myVariable, targetValue, 1.0, myEasingFunction);
factory->addAnimation(myOtherVariable, otherTargetValue, 5.0, myEasingFunction);
factory->addAnimation(myFinalVariable, finalTargetValue, 3.35, myEasingFunction);
```

All animations will automatically delete and clean themselves up.

## Examples
* None yet!  But I'll make some soon.

## Contributing
This project uses the [Git Flow](http://nvie.com/posts/a-successful-git-branching-model/) paradigm.  Before contributing, please make your own feature branch with your changes.

## More Information
None at the moment.