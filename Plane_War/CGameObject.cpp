#include "pch.h"
#include "resource.h"
#include "CGameObject.h"

//���������GameObject��ʵ�ִ���

CGameObject::CGameObject(long x, long y): obposition$(x, y) {}

CGameObject::~CGameObject() {}

CPoint CGameObject::getObPoint() { return obposition$; }

void CGameObject::setObPoint(long x, long y)
{
	obposition$.x = x;
	obposition$.y = y;
}

//params: CImageList&, λͼID�����룬ͼ������ؿ�ͼ������ظߣ���ʼ����λͼ��
BOOL CGameObject::LoadPhoto(CImageList& imgList, UINT bmpID, COLORREF crMask, int bmpw, int bmph, int nInitial)
{
	//����һ��λͼ����
	CBitmap ttbmp;	
	ttbmp.LoadBitmap(bmpID);
	imgList.Create(bmpw, bmph, ILC_COLOR24 | ILC_MASK, nInitial, 0);
	
	//ʵ��͸����ͼ, ���һ����������ָ͸������ɫ����ʾ��ʾʱ��Ҫ��ͼƬ������crMaskɫ͸����,�������ɫ��
	imgList.Add(&ttbmp, crMask);

	//����ͼ��ɹ�
	return TRUE;
}