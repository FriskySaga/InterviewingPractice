#include "ChatRoom.hpp"
#include "User.hpp"

int main()
{
  User user("Kevin");
  ChatRoom chatRoom;
  chatRoom.showMessage(user, "hello world");
  return 0;
}