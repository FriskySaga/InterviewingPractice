class User;

#include <ctime>
#include <string>

class ChatRoom
{
public:
  ChatRoom();
  void showMessage(const User& user, const std::string& message);

private:
  const std::tm* getCurrentLocalTime() const;
};