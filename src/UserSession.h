#pragma once

#include "Exceptions.h"
#include "User.h"
#include <memory>

class UserSession
{
public:
  inline static UserSession *GetInstance()
  {
    if (!oneUserSession)
    {
      oneUserSession = new UserSession();
    }
    return oneUserSession;
  }
  inline bool IsUserLoggedIn(User user)
  {
    throw CollaboratorCallException(
        "UserSession.IsUserLoggedIn() should not be called in an unit test");
  }
  inline shared_ptr<User> GetLoggedUser()
  {
    throw CollaboratorCallException(
        "UserSession.GetLoggedUser() should not be called in an unit test");
  }

private:
  static UserSession *oneUserSession;
  inline UserSession(){};
};
