#include "Bomber.h"
CREATE(CBomber)
CBomber::CBomber(void)
{
}


CBomber::~CBomber(void)
{
}
void CBomber::OnCreateGame()
{
	back.CWndBackInit(m_hIns,1);//初始化背景   加载背景图片
	Player.PlayerInit(m_hIns);  //初始化人物  加载人物图片
	::SetTimer(m_hMainWnd,PLAYER_MOVE_ID,100,0);
}
void CBomber::OnGameDraw()
{
	HDC hdc=::GetDC(m_hMainWnd);
	HDC hMenDC=::CreateCompatibleDC(hdc);
	HBITMAP hBitmap=::CreateCompatibleBitmap(hdc,600,600);
	SelectObject(hMenDC,hBitmap);
	//========================解决闪屏=============================、
	//显示背景===============
	back.BackShow(hMenDC);
	//显示炮弹
	bombbox.AllBombShow(hMenDC);
	//显示人物==============================
	Player.PlayerShow(hMenDC);

	//========================解决闪屏=============================
	DeleteObject(hBitmap);
	BitBlt(hdc,0,0,600,600,hMenDC,0,0,SRCCOPY);
	DeleteDC(hMenDC);
	ReleaseDC(m_hMainWnd,hdc);
}
void CBomber::OnGameRun(WPARAM wParam)
{
	if(wParam==PLAYER_MOVE_ID)
	{
		if(::GetAsyncKeyState(VK_LEFT))
		{
			Player.PlayerMove(VK_LEFT,back);
			if(Player.PlayerID==1)
			{
				Player.PlayerID=0;
			}
			else
			{
				Player.PlayerID=1;
			}
			Player.nFlag=2;
		}
		if(::GetAsyncKeyState(VK_RIGHT))
		{
			Player.PlayerMove(VK_RIGHT,back);
			if(Player.PlayerID==1)
			{
				Player.PlayerID=0;
			}
			else
			{
				Player.PlayerID=1;
			}
			Player.nFlag=1;
		}
		if(::GetAsyncKeyState(VK_DOWN))
		{
			Player.PlayerMove(VK_DOWN,back);
			if(Player.PlayerID==1)
			{
				Player.PlayerID=0;
			}
			else
			{
				Player.PlayerID=1;
			}
			Player.nFlag=4;
		}
		if(::GetAsyncKeyState(VK_UP))
		{
			Player.PlayerMove(VK_UP,back);
			if(Player.PlayerID==1)
			{
				Player.PlayerID=0;
			}
			else
			{
				Player.PlayerID=1;
			}
			Player.nFlag=3;
		}
	}
	this->OnGameDraw();
}
void CBomber::OnKeyDown(WPARAM wParam)
{
	if(wParam==VK_SPACE)
	{
		Player.PlayerSendBomb(bombbox,m_hIns);
	}
}
void CBomber::OnKeyUp(WPARAM wParam)
{
}