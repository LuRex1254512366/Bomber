#include "Bomb.h"


CBomb::CBomb(void)
{
	x=0;
	y=0;
	m_hBombBitmap=0;
}


CBomb::~CBomb(void)
{
	::DeleteObject(m_hBombBitmap);
}
void CBomb::InitBomb(HINSTANCE hIns,int x,int y)
{
	m_hBombBitmap=::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BOMB));
	this->x=x;
	this->y=y;
}
void CBomb::ShowBomb(HDC hMenDC)
{
	HDC hdc=::CreateCompatibleDC(hMenDC);
	::SelectObject(hdc,m_hBombBitmap);
	::BitBlt(hMenDC,x,y,30,30,hdc,0,0,SRCCOPY);
	::DeleteDC(hdc);
}