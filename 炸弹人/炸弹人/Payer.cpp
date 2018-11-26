#include "Payer.h"


CPayer::CPayer(void)
{
	m_hBitPlayerUp=0;
	m_hBitPlayerDown=0;
	m_hBitPlayerLeft=0;
	m_hBitPlayerRight=0;
	x=0;
	y=0;
	PlayerID=1;
	nFlag=1;
}


CPayer::~CPayer(void)
{
	DeleteObject(m_hBitPlayerUp);
	DeleteObject(m_hBitPlayerDown);
	DeleteObject(m_hBitPlayerLeft);
	DeleteObject(m_hBitPlayerRight);
}
void CPayer::PlayerInit(HINSTANCE hIns)
{
	m_hBitPlayerUp=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_MOVE_UP));
	m_hBitPlayerDown=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_MOVE_DOWN));
	m_hBitPlayerLeft=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_MOVE_LEFT));
	m_hBitPlayerRight=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_MOVE_RIGHT));
}
void CPayer::PlayerMove(int FX,CBack& back)
{
	if(FX==VK_UP)
	{
		if(y>0)
		{
			y-=5;
		}
	}
	if(FX==VK_DOWN)
	{
		if(y<600)
		{
			y+=5;
		}
	}
	if(FX==VK_LEFT)
	{
	
		if(x>0)
		{
			x-=5;
		}
	}
	if(FX==VK_RIGHT)
	{
	
		if(x<600)
		{
			x+=5;
		}
	}
}
void CPayer::PlayerShow(HDC hMemDC)
{
	HDC hdc=::CreateCompatibleDC(hMemDC);
	if(nFlag==1)
	{
		SelectObject(hdc,m_hBitPlayerRight);
		BitBlt(hMemDC,x,y,30,30,hdc,0,(1-PlayerID)*30,SRCCOPY);
	}
	if(nFlag==2)
	{
		SelectObject(hdc,m_hBitPlayerLeft);
		BitBlt(hMemDC,x,y,30,30,hdc,0,(1-PlayerID)*30,SRCCOPY);
	}
	if(nFlag==3)
	{
		SelectObject(hdc,m_hBitPlayerUp);
		BitBlt(hMemDC,x,y,30,30,hdc,0,(1-PlayerID)*30,SRCCOPY);
	}
	if(nFlag==4)
	{
		SelectObject(hdc,m_hBitPlayerDown);
		BitBlt(hMemDC,x,y,30,30,hdc,0,(1-PlayerID)*30,SRCCOPY);
	}
	DeleteDC(hdc);
}
void CPayer::PlayerSendBomb(CBombBox&bombbox,HINSTANCE hIns)
{
	//创建一个炸弹
	CBomb*pBomb=new CBomb;
	//初始化炸弹
	pBomb->InitBomb(hIns,x,y);
	//把炸弹装到炸弹盒子中去
	bombbox.m_bomblst.push_back(pBomb);
}
