#include "pch.h"
#include "CMyPlane.h"
#include "resource.h"
//CMyPlane.cpp

CImageList CMyPlane::mpImages;	//��̬��Ա��Ҫ���ⶨ��

//����
CMyPlane::CMyPlane() : CPlane(6, 0, 500), verticalm$(0), horizenm$(0), isdefence$(FALSE), maxtwait$(7)
{
	setObPoint(270, 500);		//�����ҵ�ս���ĳ�ʼλ��
	newObRect();
}
CMyPlane::CMyPlane(const CMyPlane& tt):CPlane(tt)
				, verticalm$(0), horizenm$(0), isdefence$(tt.isdefence$), maxtwait$(tt.maxtwait$)
{
	newObRect();
}

CMyPlane::~CMyPlane() {}

//����
void CMyPlane::setDefence(bool isd)
{
	isdefence$ = isd;
}
bool CMyPlane::getDefence()
{
	return isdefence$;
}

BOOL CMyPlane::Load()
{
	return CGameObject::LoadPhoto(mpImages, IDB_MYPLANE, RGB(255, 0, 0), MYPLANE_WIDTH, MYPLANE_HEIGHT, 1);
}

void CMyPlane::newObRect()		//����ս���ľ�����
{
	obrect$ = CRect(obposition$, CPoint(obposition$.x + MYPLANE_WIDTH, obposition$.y + MYPLANE_HEIGHT));
}

//��д�游���麯��

CRect& CMyPlane::getObRect()	//���ս���ľ�����
{
	newObRect();
	return obrect$;
}

BOOL CMyPlane::drawOb(CDC* pDC, BOOL Pause)//param���豸��������ͣ���Ʊ��
{
	if (twait$ > maxtwait$) { twait$ = 0;}
	else { twait$++; }	//����ս��װ�����

	if (!Pause)		//�������ͣ���ƵĻ�
	{
		obposition$.x += horizenm$* speed$;
		obposition$.y += verticalm$* speed$;
		newObRect();
	}
	//��û����ʾ����Ļ��
	//���ս���ɳ��ұ�Ե
	if (obposition$.x >= AREA_WIDTH - MYPLANE_WIDTH)
	{
		obposition$.x = AREA_WIDTH - MYPLANE_WIDTH;
		newObRect();
	}
	//���ս���ɳ��±�Ե
	if (obposition$.y >= AREA_HEIGHT - MYPLANE_HEIGHT)
	{
		obposition$.y = AREA_HEIGHT - MYPLANE_HEIGHT;
		newObRect();
	}
	//���ս���ɳ����Ե
	if (obposition$.x <= 0)
	{
		obposition$.x = 0;
		newObRect();
	}
	//���ս���ɳ��ϱ�Ե
	if (obposition$.y <= 0)
	{
		obposition$.y = 0;
		newObRect();
	}

	if (mpImages.Draw(pDC, 0, obposition$, ILD_TRANSPARENT))
		return TRUE;
	else
		return FALSE;
}