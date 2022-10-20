#include "colonylogic.h"

colonyLogic::colonyLogic(int count)
{
    antCount = new int(100);
}

colonyLogic::~colonyLogic()
{
    delete firstAnt;
    //NEEDS TO BE REVISED
}

void colonyLogic::CreateAnt(antLogic* parentAnt)
{
    if (parentAnt->get_child_ant() != nullptr)
    {

    }
}

void insert_ant_into_tree(antLogic* ant)
{

}
