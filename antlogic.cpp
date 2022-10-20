#include "antlogic.h"
#include <random>
#include <math.h>

antLogic::antLogic()
{
    mRot = new float{0};
    mxPos = new float{0};
    myPos = new float{0};
}

antLogic::antLogic(int number, antLogic* parent)
{
    mRot = new float{0};
    mxPos = new float{0};
    myPos = new float{0};
    antNumber = new int{number};
    parentAnt = parent;
}

antLogic::~antLogic()
{
    delete mRot;
    delete mxPos;
    delete myPos;
}

antLogic* antLogic::get_parent_ant()
{
    return parentAnt;
}

antLogic* antLogic::get_child_ant()
{
    return childAnt;
}

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

double generate_normal_random_double(double mean, double stddev)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(mean, stddev);
    return dis(gen);
}

double XMoveFromAngle(float angle)
{
    float xPart = sin( angle * 3.14159265 / 180 );
    float moveDist{5};
    return (moveDist * xPart);
}

double YMoveFromAngle(float angle)
{
    float yPart = cos( angle * 3.14159265 / 180 );
    float moveDist{5};
    return (moveDist * yPart);
}

void antLogic::Wander()
{
    //double changeRot = generate_normal_random_double(0,20);
    *mRot += generate_normal_random_double(0,20);
    *mxPos += XMoveFromAngle(*mRot);
    *myPos += YMoveFromAngle(*mRot);

}
