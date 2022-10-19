#ifndef ANTLOGIC_H
#define ANTLOGIC_H


class antLogic
{
public:
    explicit antLogic();
    ~antLogic();

    void SetPos(float x, float y);
    void SetRot(float r);

    //float get_xPos();
    //float get_yPos();


protected:
    float* mRot;
    float* mxPos;
    float* myPos;

};

#endif // ANTLOGIC_H
