#include "ifacetype.h"

#ifndef TYPEA_H
#define TYPEA_H

class TypeA: public IFaceType
{
public:
    TypeA(int size);
    ~TypeA();

    int size();
};

#endif // TYPEA_H
