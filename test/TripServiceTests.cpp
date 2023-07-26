#include "Exceptions.h"
#include "TripService.h"
#include "gtest/gtest.h"
#include <memory>

class TestableTripService : public TripService
{
public:
  shared_ptr<User> loggedInUser;
  shared_ptr<User> LoggedInUser() { return loggedInUser; }
};

TEST(TripService, GetTripsByUser_Guest_ThrowsException)
{
  auto Tom = make_shared<User>(5);
  TestableTripService tripService;

  ASSERT_THROW(tripService.GetTripsByUser(Tom), UserNotLoggedInException);
}