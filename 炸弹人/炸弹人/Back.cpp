#include "Back.h"


CBack::CBack(void)
{
	BackMapCount=0;
	//BackMapArr[19][19]
	for(int i=0;i<19;i++)
	{
		for(int j=0;j<19;j++)
		{
			BackMapArr[i][j]=0;
		}

	}
	m_hBitmap=0;
	m_hBitmap1=0;
	x=0;
	y=0;
}


CBack::~CBack(void)
{
	DeleteObject(m_hBitmap);
	DeleteObject(m_hBitmap1);
}
void CBack::CWndBackInit(HINSTANCE m_hInstance,int index)
{
	m_hBitmap=::LoadBitmap(m_hInstance,MAKEINTRESOURCE(IDB_BACK2));
	m_hBitmap1=::LoadBitmap(m_hInstance,MAKEINTRESOURCE(IDB_OBSTACLES));
	FILE* fp = 0;
	char szFilePath[100] = "..\\res\\map";
	char szNumber[10] = {0};

	char str[100] = {0};
	int i;
	int j;

	//------------------------------------------------
	//  读取关卡个数
	fopen_s(&fp,"..\\res\\Mapmaxcount.txt","rb");
	fgets(str,100,fp);
	BackMapCount = atoi(str);
	fclose(fp);
	fp = 0;
	//------------------------------------------------


	_itoa(index,szNumber,10);
	strcat_s(szFilePath,100,szNumber);
	strcat_s(szFilePath,100,".txt");

	fopen_s(&fp,szFilePath,"rb");

	//  一行一行读
	for(i=0;i<19;i++)
	{
		j=0;
		fgets(str,100,fp);
		BackMapArr[i][j]= atoi(strtok(str," "));     //  截取第一个  数字
		for(j=1;j<19;j++)
		{
			BackMapArr[i][j]= atoi(strtok(0," "));   //  截取0 和 ' ' 之间的数字
		}
	}
	fclose(fp);
}
void CBack::BackShow(HDC m_hMenDC)
{
	HDC hdc=::CreateCompatibleDC(m_hMenDC);
	HDC hdc1=::CreateCompatibleDC(m_hMenDC);
	::SelectObject(hdc,m_hBitmap);
	::SelectObject(hdc1,m_hBitmap1);
	::BitBlt(m_hMenDC,x,y,570,570,hdc,0,0,SRCCOPY);
	for(int i=0;i<19;i++)
	{
		for(int j=0;j<19;j++)
		{
			if(BackMapArr[i][j]==1)
			{
				::BitBlt(m_hMenDC,i*30,j*30,30,30,hdc1,0,0,SRCCOPY);
			}
		}
	}
	DeleteDC(hdc1);
	DeleteDC(hdc);
}