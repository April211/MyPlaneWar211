#pragma once
#include "CPlane.h"
#include "resource.h"


class CEnemyPlane : public CPlane
{
protected:
    int  verticalm$;            //���˻��Ĵ�ֱ�ƶ���ʶ��һ��Ϊ�£�+1
    enum pD { UP = 0, DOWN, LEFT, RIGHT };
private:
    static CImageList epImages; //�洢�л�ͼƬ
public:
    CEnemyPlane();
    CEnemyPlane(int hp);
    CEnemyPlane(const CEnemyPlane&);
    virtual ~CEnemyPlane();
    BOOL drawOb(CDC*, BOOL);
    CRect& getObRect();
    void newObRect();
    static BOOL Load();

    //�����ҵ�ս���Ŀ�Ⱥ͸߶�
    static const int ENEMYPLANE_WIDTH = 64;
    static const int ENEMYPLANE_HEIGHT = 47;

    friend class CPlaneWarView;
};

