#include "Exceptions.h"
#include "TripService.h"
#include "gtest/gtest.h"
#include <memory>

class TripDAOMock : public TripDAO
{
public:
  virtual const std::list<Trip> TripsByUser(shared_ptr<User> user)
  {
    return user->Trips();
  }
};

class TripServiceTests : public ::testing::Test
{
protected:
  virtual void SetUp()
  {
    registerdUser = make_shared<User>(5);
    tripDAO = std::make_shared<TripDAOMock>();
    tripService = std::make_shared<TripService>(tripDAO);
    anotherUser = make_shared<User>(20);
  }

  virtual void TearDown()
  {
    tripService.reset();
    registerdUser.reset();
    anotherUser.reset();
  }

  shared_ptr<TripDAO> tripDAO;
  shared_ptr<TripService> tripService;
  shared_ptr<User> registerdUser;
  shared_ptr<User> guest = nullptr;
  shared_ptr<User> anotherUser;
  Trip london;
  Trip paris;
};

TEST_F(TripServiceTests, GetTripsByUser_Guest_ThrowsException)
{
  auto anyUser = make_shared<User>(5);

  ASSERT_THROW(tripService->GetTripsByUser(anyUser, guest),
               UserNotLoggedInException);
}

TEST_F(TripServiceTests, GetTripsByUser_NotFriends_ReturnsNoTrips)
{
  auto stranger = make_shared<User>(5);
  stranger->AddFriend(*anotherUser);
  stranger->AddTrip(london);

  std::list<Trip> trips = tripService->GetTripsByUser(stranger, registerdUser);

  ASSERT_TRUE(trips.empty());
}

TEST_F(TripServiceTests, GetTripsByUser_Friends_ReturnsTrips)
{
  auto usersFriend = make_shared<User>(5);
  usersFriend->AddFriend(*anotherUser);
  usersFriend->AddFriend(*registerdUser);
  usersFriend->AddTrip(london);
  usersFriend->AddTrip(paris);

  std::list<Trip> trips =
      tripService->GetTripsByUser(usersFriend, registerdUser);

  ASSERT_EQ(trips.size(), 2);
}