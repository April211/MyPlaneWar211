#include "pch.h"
#include "CDefence.h"
#include "resource.h"

CImageList CDefence::dcImages;


//����
CDefence::CDefence() :CGameObject(0, 0)

{
	setObPoint(0, 0);		//�����ҵ�ս���ĳ�ʼλ��
	newObRect();
}

CDefence::CDefence(int x, int y) :CGameObject(x, y)

{
	setObPoint(x, y);		//�����ҵ�ս���ĳ�ʼλ��
	newObRect();
}

CDefence::~CDefence() {}

//����

BOOL CDefence::Load()
{
	return CGameObject::LoadPhoto(dcImages, IDB_DEFENCE, RGB(0, 0, 0), DEFENCE_WIDTH, DEFENCE_HEIGHT, 1);
}

void CDefence::newObRect()		//����ս���ľ�����
{
	obrect$ = CRect(obposition$, CPoint(obposition$.x + DEFENCE_WIDTH, obposition$.y + DEFENCE_HEIGHT));
}

//��д�游���麯��

CRect& CDefence::getObRect()	//���ս���ľ�����
{
	newObRect();
	return obrect$;
}

BOOL CDefence::drawOb(CDC* pDC, BOOL Pause)//param���豸��������ͣ���Ʊ��
{
	if (!Pause)		//�������ͣ���ƵĻ�
	{
		obposition$.x += 0;
		obposition$.y += 0;
		newObRect();
	}


	if (dcImages.Draw(pDC, 0, obposition$, ILD_TRANSPARENT))
		return TRUE;
	else
		return FALSE;

	

}