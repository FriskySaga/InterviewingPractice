#include "User.hpp"

#include "ChatRoom.hpp"

User::User(const std::string& name) :
  m_name(name)
{
  ChatRoom chatRoom;
  m_chatRoom = &chatRoom;
}

const std::string& User::getName() const
{
  return m_name;
}

void User::setName(const std::string& name)
{
  m_name = name;
}

void User::sendMessage(const std::string& message)
{
  m_chatRoom->showMessage(*this, message);
}
