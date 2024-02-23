#include "TripService.h"
#include "TripDAO.h"
#include "UserSession.h"
#include <memory>

using namespace std;

list<Trip> TripService::GetTripsByUser(shared_ptr<User> user,
                                       std::shared_ptr<User> loggedInUser)
{
  if (!loggedInUser)
  {
    throw UserNotLoggedInException("UserNotLoggedInException");
  }
  if (user->IsFriendWith(loggedInUser))
  {
    return TripsByUser(user);
  }
  return *new std::list<Trip>;
}

list<Trip> TripService::TripsByUser(shared_ptr<User> user)
{
  return TripDAO::FindTripsByUser(user);
}

void TripService::BuildCheck() { cout << "Built and runnable!" << endl; }

UserSession *UserSession::oneUserSession = 0;