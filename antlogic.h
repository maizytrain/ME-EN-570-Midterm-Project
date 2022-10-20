#ifndef ANTLOGIC_H
#define ANTLOGIC_H


class antLogic
{
public:
    explicit antLogic();
    antLogic(int number, antLogic* parent);
    ~antLogic();

    void SetPos(float x, float y);
    void SetRot(float r);

    void Wander();

    antLogic* get_parent_ant();
    antLogic* get_child_ant();

protected:
    float* mRot;
    float* mxPos;
    float* myPos;

    antLogic* parentAnt{nullptr};
    antLogic* childAnt{nullptr};
    int antNumber;

};

#endif // ANTLOGIC_H
