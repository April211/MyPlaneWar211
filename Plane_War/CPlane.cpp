#include "pch.h"
#include "CPlane.h"
#include "MainFrm.h"

//CPlane.cpp, �������ս�����ʵ��

//���캯������
CPlane::CPlane() : CGameObject(0, 0), speed$(0), score$(0), hp$(0), twait$(0) {}

CPlane::CPlane(int speed, int score, int hp) : CGameObject(0, 0), speed$(speed), score$(score)
																				,hp$(hp), twait$(0) {}

CPlane::CPlane(const CPlane& tt):speed$(tt.speed$), score$(tt.score$), hp$(tt.hp$), twait$(0)
{
	setObPoint(tt.obposition$.x, tt.obposition$.y);
}
CPlane::~CPlane() {}

//����
void CPlane::setHp(int hp) { hp$ = hp; }

void CPlane::setSpeed(int speed) { speed$ = speed; }

void CPlane::setScore(int score) { score$ = score; }

int CPlane::getHp() { return hp$; }

int CPlane::getSpeed() { return speed$; }

int CPlane::getScore() { return score$; }

bool CPlane::ifFire()//�����Ƿ񿪹��ڣ������ڵ��ص�
{
	if (twait$ == 0) //����û������
		return true;
	else             //���ڿ�����
		return false;

}

