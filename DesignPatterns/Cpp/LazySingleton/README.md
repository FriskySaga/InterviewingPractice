# Lazy Singleton Pattern
This project is a showcase of the Lazy Singleton pattern, which is a Creational pattern to guarantee the creation of only one instance of a class. The advantage of a Lazy Singleton, as opposed to a Normal or Eager Singleton, is the lazy initialization that allows us to defer expensive instantiation of objects until the time is right. In general, Lazy Singletons are preferred for this reason, and if done correctly, are thread-safe.

## Synopsis
The example leverages the Lazy Singleton pattern to create a logging utility. This example is inspired by Python's logging module which also leverages the Singleton pattern.

![Lazy Singleton Logger Diagram](Logger.png)

## Tools
* C++ 14
* CMake 3.16.3

## Resources
* https://www.wikiwand.com/en/Singleton_pattern
* https://www.tutorialspoint.com/design_pattern/singleton_pattern.htm
* https://stackoverflow.com/questions/1008019/c-singleton-design-pattern

