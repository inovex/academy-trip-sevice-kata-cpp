#pragma once

#include "Exceptions.h"
#include "Trip.h"
#include "User.h"
#include <iostream>
#include <memory>

using namespace std;

class TripDAO
{
public:
  inline static list<Trip> FindTripsByUser(shared_ptr<User> user)
  {
    throw CollaboratorCallException(
        "TripDAO should not be invoked on an unit test.");
  }
  inline virtual const std::list<Trip> TripsByUser(shared_ptr<User> user)
  {
    return TripDAO::FindTripsByUser(user);
  }
};