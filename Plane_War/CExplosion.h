#pragma once
#include "CGameObject.h"
#include "resource.h"
class CExplosion : public CGameObject
{

protected:

	//��ըͼƬ��ͼ���б�
	static CImageList exImages;

	//ͼ�������Ĳ�������������ʵ�ֱ�ը�Ķ���Ч��
	int    proc$;

public:
	CExplosion(int x, int y);
	~CExplosion();

	BOOL drawOb(CDC* pDC, BOOL bPause);
	static BOOL Load();
	CRect& getObRect();
	void newObRect();

	//������ըͼ��Ŀ��
	static const int  EXPLOSION_WIDTH  = 66;	

	//������ըͼ��ĸ߶�
	static const int  EXPLOSION_HEIGHT = 66;
};

