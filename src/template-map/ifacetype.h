#ifndef IFACETYPE_H
#define IFACETYPE_H

class IFaceType
{
public:    
    explicit IFaceType(int size);

    virtual int size() = 0;

    int size_;
};

#endif // IFACETYPE_H
