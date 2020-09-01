#include "Logger.h"

Logger::Logger()
{
  m_severity = LogSeverity::LogSeverityEnum::ERROR;
}

Logger& Logger::getInstance()
{
  static Logger instance;
  return instance;
}

const char* Logger::getSeverity()
{
  return LogSeverity::getString(m_severity);
}

void Logger::setSeverity(LogSeverity::LogSeverityEnum severity)
{
  m_severity = severity;
}

