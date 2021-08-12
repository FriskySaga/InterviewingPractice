# Observer Pattern
This project showcases the C++ implementation of the Observer pattern, which falls under the Behavorial category of design patterns from the Gang of Four.

Each Observer is updated when the Subject is updated.

This pattern represents a technique to handle coupling of different classes.

## Explanation
The client attaches the Subject to every Observer.

The client invokes `getNumber()` and `setNumber()`
to update the subject, which then notifies the Observer classes to invoke the `update()` function.

![Observer Pattern Diagram](ObserverPattern.png)

## Tools
* C++14
* g++9.3.0

## References
* https://www.tutorialspoint.com/design_pattern/observer_pattern.htm
