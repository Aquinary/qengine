#include "Header/Q.h"

void _WindowCreate( char* Caption, int X, int Y, int W, int H)
{
	/* ������� �������� ���� */                                                                                                                                                                                                    
	
	//����������� ��������� 
	QWindow -> Caption = Caption;
	QWindow -> X = X;
	QWindow -> Y = Y;
	QWindow -> W = W;
	QWindow -> H = H;
	//������� ����
	QWindow -> Window = SDL_CreateWindow
	( 
		QWindow -> Caption, 
		QWindow -> X, 
		QWindow -> Y,
		QWindow -> W,
		QWindow -> H,
		QWindow -> WindowFlags
	);
	//�������� ������� �������
	QWindow -> Render = SDL_CreateRenderer 
	(
		QWindow -> Window,
		-1,
		QWindow -> RenderFlags
	);
}

void _WindowDestroy ( )
{
	/* ������� ����������� ���� */
	SDL_DestroyWindow ( QWindow -> Window );
}

void _WindowRender ( )
{
	/* ������� ������� � ���������� ����������� */
	SDL_RenderPresent ( QWindow -> Render); 
	SDL_RenderClear ( QWindow -> Render );
}

void _WindowMaximize ( )
{
	/* ������� ������������ ���� */
	
}

void _WindowMinimize ( )
{
	/* ������� ����������� ���� */
	
}

char* _WindowCaption ( int Type, ... )
{
	/* ������� ���������/��������� ��������� ���� */
	
}
