namespace LogSeverity
{
  enum LogSeverityEnum
  {
    NOT_SET = 0,
    CRITICAL,
    INFO,
    WARN,
    ERROR,
    DEBUG,
    TRACE
  };

  static const char* LogSeverityEnumStrings[] =
  {
    "NOT_SET",
    "CRITICAL",
    "INFO",
    "WARN",
    "ERROR",
    "DEBUG",
    "TRACE"
  };

  static const char* getString(int enumValue)
  {
    return LogSeverityEnumStrings[enumValue];
  }
}

