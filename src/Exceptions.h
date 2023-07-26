#pragma once

class CollaboratorCallException
{
public:
  CollaboratorCallException(const char *m) { message = m; }

  const char *Message() { return message; }

private:
  const char *message;
};

class UserNotLoggedInException
{
public:
  UserNotLoggedInException(const char *m) { message = m; }

  const char *Message() { return message; }

private:
  const char *message;
};
