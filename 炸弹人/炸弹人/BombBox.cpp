#include "BombBox.h"


CBombBox::CBombBox(void)
{
}


CBombBox::~CBombBox(void)
{
	//ɾ������ը��
	list<CBomb*>::iterator ite=m_bomblst.begin();
	while(ite!=m_bomblst.end())
	{
		delete (*ite);//ɾ���ڵ�����
		ite=m_bomblst.erase(ite); // ɾ���ڵ�
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