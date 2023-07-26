#include "TripService.h"
#include "TripDAO.h"
#include "UserSession.h"

using namespace std;

list<Trip> TripService::GetTripsByUser(shared_ptr<User> user)
{
  list<Trip> tripList;
  shared_ptr<User> loggedUser = UserSession::GetInstance()->GetLoggedUser();
  bool isFriend = false;
  if (loggedUser)
  {
    list<User>::iterator i;
    for (i = user->GetFriends().begin(); i != user->GetFriends().end(); ++i)
    {
      if (*i == *loggedUser)
      {
        isFriend = true;
        break;
      }
    }
    if (isFriend)
    {
      tripList = TripDAO::FindTripsByUser(user);
    }
    return tripList;
  }
  else
  {
    throw UserNotLoggedInException("UserNotLoggedInException");
  }
}

void TripService::BuildCheck() { cout << "Built and runnable!" << endl; }

UserSession *UserSession::oneUserSession = 0;