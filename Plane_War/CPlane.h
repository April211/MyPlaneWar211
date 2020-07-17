#pragma once
#include "CGameObject.h"

//CPlane.h

class CPlane : public CGameObject
{
protected:
    int speed$;	          /*ս�����ٶ�*/
    int score$;	          /*ս���ĵ÷�*/
    int hp$;		      /*ս��������ֵ*/
    int twait$;           /*ս����װ��϶*/
public:
//���캯��
    CPlane();
    CPlane(int speed, int score, int hp);
    CPlane(const CPlane& tt);
    virtual ~CPlane();       //���캯���ĵ�����
//��������
    void setHp(int);
    void setSpeed(int);
    void setScore(int);
    int  getHp();
    int  getSpeed();
    int  getScore();
    
    bool ifFire();//���ս�������Ƿ񿪹��ڣ������ڵ����ص�
};

