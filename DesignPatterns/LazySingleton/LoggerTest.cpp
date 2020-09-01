// C++ includes
#include <iostream>

// Project includes
#include "Logger.h"

int main()
{
  Logger& myLogger = Logger::getInstance();
  std::cout << myLogger.getSeverity() << std::endl; // prints 'ERROR'

  myLogger.setSeverity(LogSeverity::LogSeverityEnum::DEBUG);
  std::cout << myLogger.getSeverity() << std::endl; // prints 'DEBUG'

  Logger& secondLogger = Logger::getInstance();
  std::cout << myLogger.getSeverity() << std::endl; // prints 'DEBUG' because this is the same logger as the first

  // // Constructor is private, so this will not work
  // Logger anotherLogger = Logger::Logger();

  // // Using the copy constructor for Logger should not work
  // Logger anotherLogger = Logger(myLogger);

  // // Using the assignment operator for Logger should not work
  // myLogger = secondLogger;

  return 0;
}

