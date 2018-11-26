#include "BombBox.h"


CBombBox::CBombBox(void)
{
}


CBombBox::~CBombBox(void)
{
	//删除所有炸弹
	list<CBomb*>::iterator ite=m_bomblst.begin();
	while(ite!=m_bomblst.end())
	{
		delete (*ite);//删除节点内容
		ite=m_bomblst.erase(ite); // 删除节点
	}
}
void CBombBox::AllBombShow(HDC hMenDC)
{
	list<CBomb*>::iterator ite=m_bomblst.begin();
	while(ite!=m_bomblst.end())
	{
		(*ite)->ShowBomb(hMenDC);
		++ite;
	}


}