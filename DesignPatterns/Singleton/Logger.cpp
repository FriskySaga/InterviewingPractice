#include "Logger.h"

Logger::Logger()
{
  m_severity = LogSeverity::LogSeverityEnum::ERROR;
}

Logger& Logger::getInstance()
{
  static Logger INSTANCE;
  return INSTANCE;
}

const char* Logger::getSeverity()
{
  return LogSeverity::getString(m_severity);
}

void Logger::setSeverity(LogSeverity::LogSeverityEnum severity)
{
  m_severity = severity;
}

