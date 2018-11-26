#pragma once
#include "sys.h"
class CBack
{
public:
	CBack(void);
	~CBack(void);
public:
	HBITMAP m_hBitmap;
	HBITMAP m_hBitmap1;//  ’œ∞≠ŒªÕº
	int BackMapArr[19][19];
	int BackMapCount;
	int x;
	int y;
public:
	void CWndBackInit(HINSTANCE m_hInstance,int index);
	void BackShow(HDC m_hMenDC);
};

