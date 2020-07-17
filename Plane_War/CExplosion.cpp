#include "pch.h"
#include "CExplosion.h"
#include "resource.h"

//CExplosion.cpp
CImageList CExplosion::exImages;

//����
CExplosion::CExplosion(int x, int y) :CGameObject(x, y), proc$(0) { newObRect(); }

CExplosion::~CExplosion() {}

//����
void CExplosion::newObRect()
{
	obrect$ = CRect(obposition$, CPoint(obposition$.x + EXPLOSION_WIDTH, obposition$.y + EXPLOSION_HEIGHT));
}


CRect& CExplosion::getObRect()
{
	newObRect();
	return obrect$;
}

BOOL CExplosion::drawOb(CDC* pDC, BOOL bPause)
{
	if (proc$ == 8)//8��ͼƬ,����
	{
		proc$ = 0;
		return FALSE;
	}

	exImages.Draw(pDC, proc$, obposition$, ILD_TRANSPARENT);//����λ�û���ͼ��ʵ�ֶ���Ч��
	proc$++;
	return TRUE;
}

BOOL CExplosion::Load()
{
	return CGameObject::LoadPhoto(exImages, IDB_EXPLOSION, RGB(255, 0, 0), 66, 66, 8);
}