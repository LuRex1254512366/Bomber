#pragma once
#include"sys.h"
class CBomb
{
public:
	CBomb(void);
	~CBomb(void);
public:
	int x;
	int y;
	HBITMAP m_hBombBitmap;
public:
	void InitBomb(HINSTANCE hIns,int x,int y);
	void ShowBomb(HDC hMenDC);
};

