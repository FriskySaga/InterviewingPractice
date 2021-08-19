#include "ChatRoom.hpp"

#include "User.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

ChatRoom::ChatRoom() {}

void ChatRoom::showMessage(const User& user, const std::string& message)
{
  const std::tm* now = getCurrentLocalTime();
  std::cout << std::asctime(now) << "[" << user.getName() << "] " << message << std::endl;
}

const std::tm* ChatRoom::getCurrentLocalTime() const
{
  std::time_t currentEpochTime = std::time(nullptr);
  const std::tm* currentLocalTime = std::localtime(&currentEpochTime);
  if (currentLocalTime == nullptr)
  {
    throw std::runtime_error("Mediator::getCurrentLocalTime() - currentLocalTime is NULL");
  }
  return currentLocalTime;
}