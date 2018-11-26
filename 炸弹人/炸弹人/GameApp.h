#pragma once

#ifndef _GAMEAPP_H_
#define _GAMEAPP_H_
#include <windows.h>


#define CREATE(ThisClass)\
	CGameApp* CreateObject()\
	{\
		return new ThisClass;\
	}


class CGameApp
{
public:
	HINSTANCE m_hIns;  // 当前的实例
	HWND m_hMainWnd;   //  主窗口
public:
	CGameApp()
	{
		m_hIns = 0;
		m_hMainWnd = 0;
	}
	virtual ~CGameApp()
	{
	
	}
public:
	void SetHandle(HINSTANCE hIns,HWND hwnd)
	{
		this->m_hIns = hIns;
		this->m_hMainWnd = hwnd;
	}
public:
	virtual void OnCreateGame(){}
	virtual void OnGameDraw(){}
	virtual void OnGameRun(WPARAM wParam){}
	virtual void OnKeyDown(WPARAM wParam){}
	virtual void OnKeyUp(WPARAM wParam){}
	virtual void OnLButtonDown(POINT point){}
	virtual void OnLButtonUp(POINT point){}
	virtual void OnMouseMove(POINT point){}
};


#endif//_GAMEAPP_H_
