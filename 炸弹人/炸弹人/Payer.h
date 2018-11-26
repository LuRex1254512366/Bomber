#pragma once
#include "sys.h"
#include"Back.h"
#include"BombBox.h"
class CPayer
{
public:
	CPayer(void);
	~CPayer(void);
public:
	HBITMAP m_hBitPlayerUp;
	HBITMAP	m_hBitPlayerDown;
	HBITMAP	m_hBitPlayerLeft;
	HBITMAP	m_hBitPlayerRight;
	int x;
	int y;
	int PlayerID;
	int nFlag;
	
public:
	void PlayerInit(HINSTANCE hIns);
	void PlayerMove(int FX,CBack& back);
	void PlayerShow(HDC hMemDC);
	void PlayerSendBomb(CBombBox&bombbox,HINSTANCE hIns);
};

