#include "pch.h"
#include "CEnemyPlane.h"
#include "resource.h"

//CEnemyPlane.cpp

CImageList CEnemyPlane::epImages;	//��̬��Ա��Ҫ���ⶨ��

//����
CEnemyPlane::CEnemyPlane() : CPlane((rand() % 4 + 6), 0, 10), verticalm$(1)
{
	//ս���ٶ������4��8֮��ȡֵ��ʹ�û�����ӷḻ
	setObPoint((rand() % (AREA_WIDTH - ENEMYPLANE_HEIGHT) + 1), -ENEMYPLANE_HEIGHT);//���õз�ս���ĳ�ʼλ��
	//x: ���������y: �л�һ���֣����ƶ��ͻ��������Ļ����
	newObRect();
}

CEnemyPlane::CEnemyPlane(int hp): CPlane((rand() % 4 + 6), 0, hp), verticalm$(1)
{
	//ս���ٶ������4��8֮��ȡֵ��ʹ�û�����ӷḻ
	setObPoint((rand() % (AREA_WIDTH - ENEMYPLANE_HEIGHT) + 1), -ENEMYPLANE_HEIGHT);//���õз�ս���ĳ�ʼλ��
	//x: ���������y: �л�һ���֣����ƶ��ͻ��������Ļ����
	newObRect();
}

CEnemyPlane::CEnemyPlane(const CEnemyPlane& tt) :CPlane(tt), verticalm$(1)
{
	newObRect();
}

CEnemyPlane::~CEnemyPlane() {}


BOOL CEnemyPlane::Load()
{
	return CGameObject::LoadPhoto(epImages, IDB_ENEMYPLANE, RGB(255, 0, 0), ENEMYPLANE_WIDTH, ENEMYPLANE_HEIGHT, 1);
}

void CEnemyPlane::newObRect()		//����ս���ľ�����
{
	obrect$ = CRect(obposition$, CPoint(obposition$.x + ENEMYPLANE_WIDTH, obposition$.y + ENEMYPLANE_HEIGHT));
}

//��д�游���麯��

CRect& CEnemyPlane::getObRect()	//���ս���ľ�����
{
	newObRect();
	return obrect$;
}

BOOL CEnemyPlane::drawOb(CDC* pDC, BOOL Pause)//param���豸��������ͣ���Ʊ��
{
	if (twait$ > 12) { twait$ = 0; }
	else { twait$++; }	//����ս��װ�����

	if (!Pause)		//�������ͣ���ƵĻ�
	{
		obposition$.y += verticalm$ * speed$;
		newObRect();
	}
	//��û����ʾ����Ļ��

	//���ս���ɳ��±�Ե
	if (obposition$.y > AREA_HEIGHT - ENEMYPLANE_HEIGHT)
	{
		newObRect();
		return FALSE;
	}

	if (epImages.Draw(pDC, 0, obposition$, ILD_TRANSPARENT))
		return TRUE;
	else
		return FALSE;
}