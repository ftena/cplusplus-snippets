#include <iostream>
#include <memory>
#include "writer.h"
#include "typea.h"
#include "typeb.h"

int main(int argc, char *argv[])
{
    Writer<int, IFaceType*> w;
    std::unique_ptr<TypeA> typeA (new TypeA(32));
    std::unique_ptr<TypeB> typeB (new TypeB(16));

    w.addGroup(1, typeA.get());
    w.addGroup(2, typeB.get());

    Writer<int, IFaceType*>::TemplateMap groups_map = w.getGroups();

    for (auto i = groups_map.begin(); i != groups_map.end(); i++)
    {
        std::cout << i->second->size() << std::endl;
    }

    return 0;
}

