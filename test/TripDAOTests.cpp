#include "TripService.h"
#include "gtest/gtest.h"
#include <memory>

TEST(TripDAOTests, FindTripsByUser_AnyUser_ThrowsException)
{
  TripDAO tripDao;
  shared_ptr<User> anyUser = nullptr;

  ASSERT_THROW(tripDao.TripsByUser(anyUser), CollaboratorCallException);
}