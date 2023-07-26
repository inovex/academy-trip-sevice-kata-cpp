#include "TripService.h"
#include "UserBuilder.h"
#include "gtest/gtest.h"

class UserTests : public ::testing::Test
{
protected:
  virtual void SetUp()
  {
    Paul = make_shared<User>(1);
    Bob = make_shared<User>(2);
  }

  virtual void TearDown()
  {
    Paul.reset();
    Bob.reset();
  }

  shared_ptr<User> Paul;
  shared_ptr<User> Bob;
};

TEST_F(UserTests, IsFriendWith_NoFriends_ReturnsFalse)
{
  User user = UserBuilder::aUser()->FriendsWith(1, Paul.get())->Build();

  ASSERT_FALSE(user.IsFriendWith(Bob));
}

TEST_F(UserTests, IsFriendWith_AFriend_ReturnsTrue)
{
  User user =
      UserBuilder::aUser()->FriendsWith(2, Paul.get(), Bob.get())->Build();

  ASSERT_TRUE(user.IsFriendWith(Bob));
}