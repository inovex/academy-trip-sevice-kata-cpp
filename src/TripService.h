#pragma once

#include "Trip.h"
#include "TripDAO.h"
#include "User.h"
#include <iostream>
#include <list>
#include <memory>

using namespace std;

class TripService
{
public:
  TripService(shared_ptr<TripDAO> _tripDao) : tripDao(_tripDao) {}
  list<Trip> GetTripsByUser(shared_ptr<User> user,
                            shared_ptr<User> loggedInUser);
  void BuildCheck();

private:
  std::shared_ptr<TripDAO> tripDao;
};