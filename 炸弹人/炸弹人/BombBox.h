#pragma once
#include"Bomb.h"
#include"sys.h"
class CBombBox
{
public:
	CBombBox(void);
	~CBombBox(void);
public:
	list<CBomb*> m_bomblst;  //װը��������
public:
	void AllBombShow(HDC hMenDC);  //����ը������ʾ
};

