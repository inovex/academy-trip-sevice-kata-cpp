#include "Exceptions.h"
#include "TripService.h"
#include "gtest/gtest.h"
#include <memory>

class TestableTripService : public TripService
{
public:
  shared_ptr<User> loggedInUser;
  shared_ptr<User> LoggedInUser() { return loggedInUser; }
  list<Trip> TripsByUser(shared_ptr<User> user) { return user->Trips(); }
};

class TripServiceTests : public ::testing::Test
{
protected:
  virtual void SetUp()
  {
    registerdUser = make_shared<User>(5);
    tripService = make_shared<TestableTripService>();
    tripService->loggedInUser = registerdUser;
    anotherUser = make_shared<User>(20);
  }

  virtual void TearDown()
  {
    tripService.reset();
    registerdUser.reset();
    anotherUser.reset();
  }

  shared_ptr<TestableTripService> tripService;
  shared_ptr<User> registerdUser;
  shared_ptr<User> guest = nullptr;
  shared_ptr<User> anotherUser;
  Trip london;
  Trip paris;
};

TEST_F(TripServiceTests, GetTripsByUser_Guest_ThrowsException)
{
  tripService->loggedInUser = guest;
  auto anyUser = make_shared<User>(5);

  ASSERT_THROW(tripService->GetTripsByUser(anyUser), UserNotLoggedInException);
}

TEST_F(TripServiceTests, GetTripsByUser_NotFriends_ReturnsNoTrips)
{
  auto stranger = make_shared<User>(5);
  stranger->AddFriend(*anotherUser);
  stranger->AddTrip(london);

  std::list<Trip> trips = tripService->GetTripsByUser(stranger);

  ASSERT_TRUE(trips.empty());
}

TEST_F(TripServiceTests, GetTripsByUser_Friends_ReturnsTrips)
{
  auto usersFriend = make_shared<User>(5);
  usersFriend->AddFriend(*anotherUser);
  usersFriend->AddFriend(*registerdUser);
  usersFriend->AddTrip(london);
  usersFriend->AddTrip(paris);

  std::list<Trip> trips = tripService->GetTripsByUser(usersFriend);

  ASSERT_EQ(trips.size(), 2);
}