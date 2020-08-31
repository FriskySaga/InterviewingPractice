#include "LogSeverityEnum.h"

class Logger
{
private:
  Logger();
  LogSeverity::LogSeverityEnum m_severity;

public:
  static Logger& getInstance();

  const char* getSeverity();

  void setSeverity(LogSeverity::LogSeverityEnum severity);
};

