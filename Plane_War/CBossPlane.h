#pragma once
#include "CEnemyPlane.h"
#include "resource.h"
class CBossPlane : public CPlane
{
private:
    static CImageList bp1Images; //�洢BOSS1ͼƬ
    static CImageList bp2Images; //�洢BOSS2ͼƬ
    static CImageList bp3Images; //�洢BOSS3ͼƬ
    static CImageList bp4Images; //�洢BOSS4ͼƬ
public:
    CBossPlane(int id, int hp);
    CBossPlane(const CBossPlane&);
    virtual ~CBossPlane();
    BOOL drawOb(CDC*, BOOL);
    CRect& getObRect();
    void newObRect();
    static BOOL Load();
    enum BossId
    {
        enfirst = 0,
        ensecond,
        enthird,
        enforth
    };
protected:
    int id$;        //ȷ��BOSS�ͺ�
    int verticalm$;



    //����BOSS��ս���Ŀ�Ⱥ͸߶�
    static const int BOSSPLANE1_WIDTH  = 122;
    static const int BOSSPLANE1_HEIGHT = 114;

    static const int BOSSPLANE2_WIDTH  = 119;
    static const int BOSSPLANE2_HEIGHT = 110;

    static const int BOSSPLANE3_WIDTH  = 131;
    static const int BOSSPLANE3_HEIGHT = 92;

    static const int BOSSPLANE4_WIDTH  = 125;
    static const int BOSSPLANE4_HEIGHT = 84;

    friend class CPlaneWarView;

};



