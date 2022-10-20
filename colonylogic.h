#ifndef COLONYLOGIC_H
#define COLONYLOGIC_H

#include "antlogic.h"


class colonyLogic
{
public:
    explicit colonyLogic(int count);
    ~colonyLogic();

    void CreateAnt(antLogic* parentAnt);

private:
    antLogic* firstAnt{nullptr};
    antLogic* lastInsertedAnt{nullptr};
    int* antCount{nullptr};
};

#endif // COLONYLOGIC_H
