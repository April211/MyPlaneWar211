#include "pch.h"
#include "CBossPlane.h"
#include "resource.h"

//CBossPlane.cpp

CImageList CBossPlane::bp1Images;	//��̬��Ա��Ҫ���ⶨ��
CImageList CBossPlane::bp2Images;	//��̬��Ա��Ҫ���ⶨ��
CImageList CBossPlane::bp3Images;	//��̬��Ա��Ҫ���ⶨ��
CImageList CBossPlane::bp4Images;	//��̬��Ա��Ҫ���ⶨ��

//����
CBossPlane::CBossPlane(int id, int hp) : CPlane(2, 0, hp), id$(id), verticalm$(1)
{
	if (id$ == 0)
	{
		//BOSS�ٶ������4��8֮��ȡֵ��ʹ�û�����ӷḻ
		setObPoint(BOSSPLANE1_WIDTH, -BOSSPLANE1_HEIGHT);//����BOSS�ĳ�ʼλ��
		//x: ���������y: �л�һ���֣����ƶ��ͻ��������Ļ����
		newObRect();
	}
	else if (id$ == 1)
	{
		//BOSS�ٶ������4��8֮��ȡֵ��ʹ�û�����ӷḻ
		setObPoint(BOSSPLANE2_WIDTH, -BOSSPLANE2_HEIGHT);//����BOSS�ĳ�ʼλ��
		//x: ���������y: �л�һ���֣����ƶ��ͻ��������Ļ����
		newObRect();
	}
	else if (id$ == 2)
	{
		//BOSS�ٶ������4��8֮��ȡֵ��ʹ�û�����ӷḻ
		setObPoint(BOSSPLANE3_WIDTH, -BOSSPLANE3_HEIGHT);//����BOSS�ĳ�ʼλ��
		//x: ���������y: �л�һ���֣����ƶ��ͻ��������Ļ����
		newObRect();
	}
	else
	{
		//BOSS�ٶ������4��8֮��ȡֵ��ʹ�û�����ӷḻ
		setObPoint(BOSSPLANE4_WIDTH, -BOSSPLANE4_HEIGHT);//����BOSS�ĳ�ʼλ��
		//x: ���������y: �л�һ���֣����ƶ��ͻ��������Ļ����
		newObRect();
	}

}

CBossPlane::CBossPlane(const CBossPlane& tt) :CPlane(tt), id$(tt.id$), verticalm$(tt.verticalm$)
{
	newObRect();
}

CBossPlane::~CBossPlane() {}


BOOL CBossPlane::Load()
{
	if ((CGameObject::LoadPhoto(bp1Images, IDB_BOSS1, RGB(0, 0, 0), BOSSPLANE1_WIDTH, BOSSPLANE1_HEIGHT, 1))
		&& (CGameObject::LoadPhoto(bp2Images, IDB_BOSS2, RGB(0, 0, 0), BOSSPLANE2_WIDTH, BOSSPLANE2_HEIGHT, 1))
		&& (CGameObject::LoadPhoto(bp3Images, IDB_BOSS3, RGB(0, 0, 0), BOSSPLANE3_WIDTH, BOSSPLANE3_HEIGHT, 1))
		&& (CGameObject::LoadPhoto(bp4Images, IDB_BOSS4, RGB(0, 0, 0), BOSSPLANE4_WIDTH, BOSSPLANE4_HEIGHT, 1))
		)
		return TRUE;
	else return FALSE;
}



void CBossPlane::newObRect()		//����ս���ľ�����
{
	if (id$ == enfirst)
	{
		obrect$ = CRect(obposition$, CPoint(obposition$.x + BOSSPLANE1_WIDTH, obposition$.y + BOSSPLANE1_HEIGHT));

	}
	else if (id$ == ensecond)
	{
		obrect$ = CRect(obposition$, CPoint(obposition$.x + BOSSPLANE2_WIDTH, obposition$.y + BOSSPLANE2_HEIGHT));

	}
	else if (id$ == enthird)
	{
		obrect$ = CRect(obposition$, CPoint(obposition$.x + BOSSPLANE3_WIDTH, obposition$.y + BOSSPLANE3_HEIGHT));
	}
	else
	{
		obrect$ = CRect(obposition$, CPoint(obposition$.x + BOSSPLANE4_WIDTH, obposition$.y + BOSSPLANE4_HEIGHT));
	}
}

//��д�游���麯��

CRect& CBossPlane::getObRect()	//���ս���ľ�����
{
	newObRect();
	return obrect$;
}

BOOL CBossPlane::drawOb(CDC* pDC, BOOL Pause)//param���豸��������ͣ���Ʊ��
{
	if (twait$ > 30) { twait$ = 0; }
	else { twait$++; }	//����BOSSװ�����

	if (!Pause)		//�������ͣ���ƵĻ�
	{
		obposition$.y += verticalm$ * speed$;
		newObRect();
	}
	//��û����ʾ����Ļ��

	if (id$ == enfirst)
	{
		if (obposition$.y > BOSSPLANE1_HEIGHT)
		{
			//��BOSS��ֹ��һ���ط�
			obposition$.y = BOSSPLANE1_HEIGHT;
			newObRect();
		}

		if (bp1Images.Draw(pDC, 0, obposition$, ILD_TRANSPARENT))
			return TRUE;
		else
			return FALSE;
	}

	else if (id$ == ensecond)
	{
		//��BOSS��ֹ��һ���ط�
		if (obposition$.y > BOSSPLANE2_HEIGHT)
		{
			obposition$.y = BOSSPLANE2_HEIGHT;
			newObRect();
		}

		if (bp2Images.Draw(pDC, 0, obposition$, ILD_TRANSPARENT))
			return TRUE;
		else
			return FALSE;
	}

	else if (id$ == enthird)
	{
		//��BOSS��ֹ��һ���ط�
		if (obposition$.y > BOSSPLANE3_HEIGHT)
		{
			obposition$.y = BOSSPLANE3_HEIGHT;
			newObRect();
		}

		if (bp3Images.Draw(pDC, 0, obposition$, ILD_TRANSPARENT))
			return TRUE;
		else
			return FALSE;
	}

	else
	{
		//��BOSS��ֹ��һ���ط�
		if (obposition$.y > BOSSPLANE4_HEIGHT)
		{
			obposition$.y = BOSSPLANE4_HEIGHT;
			newObRect();
		}

		if (bp4Images.Draw(pDC, 0, obposition$, ILD_TRANSPARENT))
			return TRUE;
		else
			return FALSE;
	}



}