#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <exception>

class myexception: public exception
{

  public:

  virtual const char* what() const throw()
  {
    return "[class::myexception] My exception happened";
  }
};

#endif

