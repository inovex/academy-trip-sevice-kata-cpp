#include "UserBuilder.h"
#include "TripService.h"
#include "User.h"
#include <stdarg.h>

UserBuilder *UserBuilder::FriendsWith(int count, ...) {
  va_list arguments;

  va_start(arguments, count);

  for (int x = 0; x < count; x++) {
    friends.push_back(va_arg(arguments, User));
  }

  va_end(arguments);

  return this;
}

UserBuilder *UserBuilder::WithTripsTo(int count, ...) {
  va_list arguments;

  va_start(arguments, count);

  for (int x = 0; x < count; x++) {
    trips.push_back(va_arg(arguments, Trip));
  }

  va_end(arguments);

  return this;
}

User UserBuilder::Build() {
  User user(1);

  for (std::list<User>::iterator aFriend = friends.begin();
       aFriend != friends.end(); aFriend++) {
    user.AddFriend(*aFriend);
  }

  for (std::list<Trip>::iterator trip = trips.begin(); trip != trips.end();
       trip++) {
    user.AddTrip(*trip);
  }

  return user;
}