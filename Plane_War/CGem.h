#pragma once
#include "CGameObject.h"
#include "pch.h"

class CGem :
    public CGameObject
{
protected:
	int plushp$;
	int speed$;
	int direction$;	//�л��ӵ����з���һ��Ϊ1��down
public:
	CGem();
	CGem(long x, long y, int direction);
	virtual ~CGem();

	//���� һ����Ϸ����param���豸��������ͣ���Ʊ��
	BOOL drawOb(CDC*, BOOL);

	//��ö���ľ������򣬴��麯��
	CRect& getObRect();

	//���¾���
	void   newObRect();

	//���ض���ͼ��
	static BOOL Load();

	//�����ҵĳ��浼���Ŀ�Ⱥ͸߶�
	static const int GEM_WIDTH = 22;
	static const int GEM_HEIGHT = 27;
	static CImageList gmImages;

	friend class CPlaneWarView;
};

