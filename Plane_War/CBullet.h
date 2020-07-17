#pragma once
#include "CGameObject.h"
class CBullet :
    public CGameObject
{
protected:
    int atk$;             /*��ҩ�Ĺ�����*/
    int speed$;           /*��ҩ�ķ����ٶ�*/
public:
//���캯��
    CBullet();
    CBullet(int atk, int speed);
    CBullet(int x, int y, int atk, int speed);
    CBullet(const CBullet& tt);
    virtual ~CBullet();       
//��������
    void setSpeed(int);
    void setAtk(int);
    int  getSpeed();
    int  getAtk();
};


