#pragma once
#include"Bomb.h"
#include"sys.h"
class CBombBox
{
public:
	CBombBox(void);
	~CBombBox(void);
public:
	list<CBomb*> m_bomblst;  //装炸弹的链表
public:
	void AllBombShow(HDC hMenDC);  //所有炸弹的显示
};

