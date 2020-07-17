#pragma once
#include "CPlane.h"
#include "resource.h"

//CMyPlane.h
class CMyPlane : public CPlane
{
protected:
    BOOL isdefence$;              /*�ҵ�ս���Ƿ�ӵ�м�����*/
    int  horizenm$;             /*ս����ˮƽ�ƶ���ʶ����-1����ֹ0����+1*/
    int  verticalm$;            /*ս���Ĵ�ֱ�ƶ���ʶ����+1����ֹ0����-1*/
    int  maxtwait$;             //��ؿ��仯���������
    enum pD { UP = 0, DOWN, LEFT, RIGHT};
private:
    static CImageList mpImages; /*�洢�ҵ�ս��ͼƬ*/
public:
    CMyPlane();
    CMyPlane(const CMyPlane&);
    virtual ~CMyPlane();
    void setDefence(bool);
    bool getDefence();
    BOOL drawOb(CDC*, BOOL);
    CRect& getObRect();
    void newObRect();
    static BOOL Load();
     

    //�����ҵ�ս���Ŀ�Ⱥ͸߶�
    static const int MYPLANE_WIDTH = 64;    
    static const int MYPLANE_HEIGHT = 48;

    friend class CPlaneWarView;
};

