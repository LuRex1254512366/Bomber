#include <windows.h>
#include "GameApp.h"
#include <windowsx.h>
#include <time.h>
// HINSTANCE ʵ�����           ����һ���ⲿ����Դ��Ҫ��
// HWND      ������           �ʹ�����صĲ���
// HDC       �����豸���       ��ͼ�Ĳ���

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

	//  1. ���
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
	wndclass.lpszClassName = "ը����";
	wndclass.lpszMenuName = 0;
	wndclass.style = CS_VREDRAW|CS_HREDRAW;
	//  2. ע��
	if( ::RegisterClassEx(&wndclass)==FALSE)
	{
		::MessageBox(0,"ע��ʧ��","��ʾ",MB_OK);
		return 0;
	}
	//  3. ����
	HWND hwnd = ::CreateWindow("ը����","ը����",WS_OVERLAPPEDWINDOW,300,0,570+16,570+38,0,0,hInstance,0);
	if(hwnd == 0)
	{
		::MessageBox(0,"����ʧ��","��ʾ",MB_OK);
		return 0;		
	}
	//  4. ��ʾ
	::ShowWindow(hwnd,SW_SHOW);
	//  5. ��Ϣѭ��
	MSG msg;
	while(::GetMessage(&msg,0,0,0))
	{
		//  ����
		::TranslateMessage(&msg);
		//  �ַ�
		::DispatchMessage(&msg);
	}


	return 0;
}

CGameApp* pApp = 0;
CGameApp* CreateObject();  //  ����һ������Ķ���

//  ��Ϣ�Ĵ�����
LRESULT CALLBACK WndProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		{
			// ������Ϸ�Ķ���
			pApp = CreateObject();

			if(pApp != 0)
			{
				//  ���þ��
				pApp->SetHandle(g_hIns,hwnd);
				//  ��ʼ����Ϸ��������Դ
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