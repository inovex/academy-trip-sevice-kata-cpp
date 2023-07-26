#include "TripService.h"
#include "UserSession.h"

int main()
{
  auto service = make_shared<TripService>();

  service->BuildCheck();

  return 0;
}
