#pragma once
#include <afx.h>

//Designed by Wuguangkai211, Frank, 2020/06 - 2020/07

//����������Ϸ����ĸ����������public�̳���CObject����ʵ�ַ�����Ӧ��xxx.cpp�ļ���

class CGameObject : public CObject
{
protected:
	//��������λ�õĶ�ά���꣨���Ͻǣ�
	CPoint obposition$;

	//�������ڵľ�������
	CRect  obrect$;

public:
	//����Ĭ�ϲ����Ĺ��캯��
	CGameObject(long x = 0, long y = 0);	

	//��������������֤���ж�����ȫ����
	virtual ~CGameObject();			

    //��ö�������
	CPoint getObPoint();

	//������Ϸ��������
	void   setObPoint(long, long);

	//���� һ����Ϸ����param���豸��������ͣ���Ʊ�Ǵ��麯��
	virtual BOOL drawOb(CDC*, BOOL) = 0;

	//��ö���ľ������򣬴��麯��
	virtual CRect& getObRect() = 0;

	//���� �����ͼ��
	//params: CImageList&, λͼID�����룬ͼ������ؿ�ͼ������ظߣ���ʼ����λͼ��
	static BOOL LoadPhoto(CImageList&, UINT, COLORREF, int, int, int);
};
