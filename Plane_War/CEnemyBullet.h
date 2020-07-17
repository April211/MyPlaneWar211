#pragma once
#include "CBullet.h"
#include "resource.h"
#define DOWN   1

class CEnemyBullet : public CBullet
{
protected:
	int direction$;	//�л��ӵ����з���һ��Ϊ1��down
public:
	CEnemyBullet();
	CEnemyBullet(long x, long y, int speed, int atk, int direction);
	virtual ~CEnemyBullet();

	//���� һ����Ϸ����param���豸��������ͣ���Ʊ��
	BOOL drawOb(CDC*, BOOL);

	//��ö���ľ������򣬴��麯��
	CRect& getObRect();

	//���¾���
	void   newObRect();

	//���ض���ͼ��
	static BOOL Load();

	//�����ҵĳ��浼���Ŀ�Ⱥ͸߶�
	static const int ENEMYBULLET_WIDTH = 8;
	static const int ENEMYBULLET_HEIGHT = 8;
	static CImageList ebImages;
};

