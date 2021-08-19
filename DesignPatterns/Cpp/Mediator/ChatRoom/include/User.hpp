class ChatRoom;

#include <string>

class User
{
public:
  User(const std::string& name);
  const std::string& getName() const;
  void setName(const std::string& name);
  void sendMessage(const std::string& message);

private:
  std::string m_name;
  ChatRoom* m_chatRoom;
};