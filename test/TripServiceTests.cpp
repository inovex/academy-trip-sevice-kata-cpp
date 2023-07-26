#include "Exceptions.h"
#include "TripService.h"
#include "gtest/gtest.h"
#include <memory>

TEST(TripService, GetTripsByUser_Guest_ThrowsException)
{
  auto Tom = make_shared<User>(5);
  TripService tripService;

  ASSERT_THROW(tripService.GetTripsByUser(Tom), UserNotLoggedInException);
}