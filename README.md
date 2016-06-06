# ofxAnimation.h

## Requirements
* C++11 (is anyone *not* using this these days?)

## Usage
To use this library, include `ofxAnimation.h`.

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
factory->addAnimation(myVariable, targetValue, 1000, myEasingFunction);
factory->addAnimation(myOtherVariable, otherTargetValue, 5000, myEasingFunction);
factory->addAnimation(myFinalVariable, finalTargetValue, 3350, myEasingFunction);
```

The types of variables that can be animated are `float`, `ofColor`, and `ofPoint` -- for each of them use the
`addAnimation()` function:

```
factory->addAnimation(myFloat, 1234.567, 1000, myEasingFunction);
factory->addAnimation(myColor, ofColor(255, 0, 255, 128), 5000, myEasingFunction);
factory->addAnimation(myPoint, ofPoint(ofGetWidth/2.0, ofGetHeight()/2.0, 0.0), 3350, myEasingFunction);
```

Once you've added animations, just run `AnimationFactory::update()` in your loop -- this will update the clock for each
animation and update their values.

There are also optional callbacks that can be run when the animation is updating, or when it is completed.  Read the
header files to find out more about how to use these.

## Examples
* None yet!  But I'll make some soon.

## Contributing
This project uses the [Git Flow](http://nvie.com/posts/a-successful-git-branching-model/) paradigm.  Before contributing, please make your own feature branch with your changes.

## More Information
None at the moment.
