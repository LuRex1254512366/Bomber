#pragma once
#include "gameapp.h"
#include "Back.h"
#include"Payer.h"
#include"BombBox.h"
class CBomber :
	public CGameApp
{
public:
	CBack back;
	CPayer Player;
	CBomb bomb;
	CBombBox bombbox;
public:
	CBomber(void);
	~CBomber(void);
public:
	virtual void OnCreateGame();
	virtual void OnGameDraw();
	virtual void OnGameRun(WPARAM wParam);
	virtual void OnKeyDown(WPARAM wParam);
	virtual void OnKeyUp(WPARAM wParam);
};