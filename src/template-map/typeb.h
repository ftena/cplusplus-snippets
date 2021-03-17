#include "ifacetype.h"

#ifndef TYPEB_H
#define TYPEB_H

class TypeB: public IFaceType
{
public:
    TypeB(int size);
    ~TypeB();

    int size();
};

#endif // TYPEA_B

