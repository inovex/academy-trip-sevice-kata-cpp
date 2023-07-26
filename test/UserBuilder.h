#pragma once

#include "TripService.h"

class UserBuilder {
public:
  static UserBuilder *aUser() { return new UserBuilder(); }

  UserBuilder *FriendsWith(int count, ...);

  UserBuilder *WithTripsTo(int count, ...);

  User Build();

private:
  std::list<Trip> trips;
  std::list<User> friends;
};
