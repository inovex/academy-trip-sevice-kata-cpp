#pragma once

#include "Trip.h"
#include <iostream>
#include <list>
#include <memory>

using namespace std;

class User
{
public:
  inline User(int _id) : id(_id){};

  inline list<User> &GetFriends() { return friends; }

  inline void AddFriend(User user) { friends.push_back(user); }

  inline list<Trip> &Trips() { return trips; }

  inline void AddTrip(Trip trip) { trips.push_back(trip); }

  inline bool operator==(User &other) { return (other.id == id); }

  inline bool IsFriendWith(shared_ptr<User> user)
  {
    for (auto i = friends.begin(); i != friends.end(); ++i)
    {
      if (*i == *user.get())
      {
        return true;
      }
    }
    return false;
  }

private:
  int id;
  list<Trip> trips;
  list<User> friends;
};