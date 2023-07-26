#include "TripService.h"
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
  User user(5);
  user.AddFriend(*Paul.get());

  ASSERT_FALSE(user.IsFriendWith(Bob));
}

TEST_F(UserTests, IsFriendWith_AFriend_ReturnsTrue)
{
  User user(5);
  user.AddFriend(*Paul.get());
  user.AddFriend(*Bob.get());

  ASSERT_TRUE(user.IsFriendWith(Bob));
}