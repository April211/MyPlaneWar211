#pragma once
#include "CMyBullet.h"
#include "resource.h"

#define UP	  -1
#define DOWN   1

class CRegularBullet : public CMyBullet
{
protected:
	int direction$;	//-1up, 1down

public:
	CRegularBullet();
	CRegularBullet(long x, long y, int speed, int atk, int direction);
	virtual ~CRegularBullet();

	//���� һ����Ϸ����param���豸��������ͣ���Ʊ�Ǵ��麯��
	BOOL drawOb(CDC*, BOOL);

	//��ö���ľ������򣬴��麯��
	CRect& getObRect();

	//���¾���
	void   newObRect();

	//���ض���ͼ��
	static BOOL  Load();

	//�����ҵĳ��浼���Ŀ�Ⱥ͸߶�
	static const int REGULARBULLET_WIDTH = 10;    
	static const int REGULARBULLET_HEIGHT = 33;
	static CImageList rbImages;
};



