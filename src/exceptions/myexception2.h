#ifndef MYEXCEPTION2_H
#define MYEXCEPTION2_H

#include <exception>

class myexception2: public exception
{

  public:

  virtual const char* what() const throw()
  {
    return "[class::myexception2] My exception 2 happened";
  }
};

#endif

