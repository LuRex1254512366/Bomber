#include <windows.h>
#include "GameApp.h"
#include <windowsx.h>
#include <time.h>
// HINSTANCE 实例句柄           加载一个外部的资源需要用
// HWND      代表窗口           和窗口相关的操作
// HDC       环境设备句柄       绘图的操作

// Window Message
// WM_LBUTTONDOWN
// WM_KEYDOWN
// WM_PAINT
// WM_TIMER
// ........

LRESULT CALLBACK WndProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
HINSTANCE g_hIns;

int CALLBACK WinMain(HINSTANCE hInstance,HINSTANCE hPreInstance,LPSTR pCmdLine,int nCmdShow)
{
	g_hIns = hInstance;
	srand((unsigned int)time(0));

	//  1. 设计
	WNDCLASSEX wndclass;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wndclass.hCursor = ::LoadCursor(0,MAKEINTRESOURCE(IDC_ARROW));
	wndclass.hIcon = 0;
	wndclass.hIconSm = 0;
	wndclass.hInstance = hInstance;
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = "炸弹人";
	wndclass.lpszMenuName = 0;
	wndclass.style = CS_VREDRAW|CS_HREDRAW;
	//  2. 注册
	if( ::RegisterClassEx(&wndclass)==FALSE)
	{
		::MessageBox(0,"注册失败","提示",MB_OK);
		return 0;
	}
	//  3. 创建
	HWND hwnd = ::CreateWindow("炸弹人","炸弹人",WS_OVERLAPPEDWINDOW,300,0,570+16,570+38,0,0,hInstance,0);
	if(hwnd == 0)
	{
		::MessageBox(0,"创建失败","提示",MB_OK);
		return 0;		
	}
	//  4. 显示
	::ShowWindow(hwnd,SW_SHOW);
	//  5. 消息循环
	MSG msg;
	while(::GetMessage(&msg,0,0,0))
	{
		//  翻译
		::TranslateMessage(&msg);
		//  分发
		::DispatchMessage(&msg);
	}


	return 0;
}

CGameApp* pApp = 0;
CGameApp* CreateObject();  //  创建一个子类的对象

//  消息的处理函数
LRESULT CALLBACK WndProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		{
			// 窗口游戏的对象
			pApp = CreateObject();

			if(pApp != 0)
			{
				//  设置句柄
				pApp->SetHandle(g_hIns,hwnd);
				//  初始化游戏，加载资源
				pApp->OnCreateGame();
			}
		}
		break;
	case WM_PAINT:
		{
			if(pApp != 0)
				pApp->OnGameDraw();
		}
		break;
	case WM_TIMER:
		{
			if(pApp != 0)
				pApp->OnGameRun(wParam);
		}
		break;
	case WM_KEYDOWN:
		{
			if(pApp != 0)
				pApp->OnKeyDown(wParam);
		}
		break;
	case WM_KEYUP:
		{
			if(pApp != 0)
				pApp->OnKeyUp(wParam);
		}
		break;
	case WM_LBUTTONDOWN:
		{
			if(pApp != 0)
			{
				POINT point;
				point.x = LOWORD(lParam);
				point.y = HIWORD(lParam);
				//point.x = GET_X_LPARAM(lParam); 
				//point.y = GET_Y_LPARAM(lParam);
				pApp->OnLButtonDown(point);
			}
		}
		break;
	case WM_LBUTTONUP:
		{
			if(pApp != 0)
			{
				POINT point;
				point.x = LOWORD(lParam);
				point.y = HIWORD(lParam);
				pApp->OnLButtonUp(point);
			}
		}
		break;
	case WM_MOUSEMOVE:
		{
			if(pApp != 0)
			{
				POINT point;
				point.x = LOWORD(lParam);
				point.y = HIWORD(lParam);
				pApp->OnMouseMove(point);
			}
		}
		break;
	case WM_CLOSE:
		{
			delete pApp;
			pApp = 0;
			::PostQuitMessage(0);
		}
		break;
	}
	return ::DefWindowProc( hwnd, uMsg, wParam, lParam);
}