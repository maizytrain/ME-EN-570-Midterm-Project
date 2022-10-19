#include "antlogic.h"

antLogic::antLogic()
{
    mRot = new float{0};
    mxPos = new float{0};
    myPos = new float{0};
}

antLogic::~antLogic()
{
    delete mRot;
    delete mxPos;
    delete myPos;
}

/*float antLogic::get_xPos()
{
    return *mxPos;
}

float antLogic::get_yPos()
{
    float temp{*myPos};
    return temp;
}*/

void antLogic::SetPos(float x, float y)
{
    //delete mxPos;
    //delete myPos;
    *mxPos = x;
    *myPos = y;
}

void KeeprUnder360(float& r)
{
    if (r >= 360)
    {
        r -= 360;
        KeeprUnder360(r);
    }
}

void antLogic::SetRot(float r)
{
    KeeprUnder360(r);
    *mRot = r;
}


