#pragma once

#include "Trip.h"
#include "User.h"
#include <iostream>
#include <list>
#include <memory>

using namespace std;

class TripService
{
public:
  list<Trip> GetTripsByUser(shared_ptr<User> user,
                            std::shared_ptr<User> loggedInUser);
  void BuildCheck();

protected:
  virtual list<Trip> TripsByUser(shared_ptr<User> user);
};