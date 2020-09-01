#include "LogSeverityEnum.h"

class Logger
{
private:
  Logger();

public:
  Logger(Logger const&) = delete;
  void operator=(Logger const&) = delete;

  /**
   * Lazy Singleton initialization
   */
  static Logger& getInstance();

  /**
   * @return The log severity, e.g., "WARN"
   */
  const char* getSeverity();

  /**
   * @param severity The log severity to set
   */
  void setSeverity(LogSeverity::LogSeverityEnum severity);

private:
  LogSeverity::LogSeverityEnum m_severity;
};

