#pragma once
#include "CGameObject.h"
class CDefence : public CGameObject
{
private:
    static CImageList dcImages; /*�洢�ҵ�ս��ͼƬ*/
public:
    CDefence();
    CDefence(int x, int y);
    CDefence(const CDefence&);
    virtual ~CDefence();

    BOOL drawOb(CDC*, BOOL);
    CRect& getObRect();
    void newObRect();
    static BOOL Load();


    //�����ҵ�ս���Ŀ�Ⱥ͸߶�
    static const int DEFENCE_WIDTH  = 80;
    static const int DEFENCE_HEIGHT = 41;
    static const int LAST = 100;

    friend class CPlaneWarView;
};

