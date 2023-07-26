#include "TripService.h"
#include "TripDAO.h"
#include "UserSession.h"
#include <memory>

using namespace std;

list<Trip> TripService::GetTripsByUser(shared_ptr<User> user)
{
  shared_ptr<User> loggedUser = LoggedInUser();
  if (!loggedUser)
  {
    throw UserNotLoggedInException("UserNotLoggedInException");
  }
  if (user->IsFriendWith(loggedUser))
  {
    return TripsByUser(user);
  }
  return *new std::list<Trip>;
}

shared_ptr<User> TripService::LoggedInUser()
{
  return UserSession::GetInstance()->GetLoggedUser();
}

list<Trip> TripService::TripsByUser(shared_ptr<User> user)
{
  return TripDAO::FindTripsByUser(user);
}

void TripService::BuildCheck() { cout << "Built and runnable!" << endl; }

UserSession *UserSession::oneUserSession = 0;