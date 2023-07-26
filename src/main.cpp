#include "TripService.h"
#include "UserSession.h"
#include <memory>

int main()
{
  auto service = make_shared<TripService>(make_shared<TripDAO>());

  service->BuildCheck();

  return 0;
}
