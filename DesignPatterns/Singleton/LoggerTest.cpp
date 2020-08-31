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
  // anotherLogger.getSeverity();

  return 0;
}

