#include "Header/Q.h"

void QInit( )
{
	/* ������� ������������� Q */
	
	//��������� ������ ��� ���������� ���������
	QWindow = malloc ( sizeof ( struct _qwindow ));
	QEvent = malloc ( sizeof ( struct _qevent ));
	QImage = malloc ( sizeof ( struct _qimage));
	QScene = malloc ( sizeof ( struct _qscene));
	int i;
	for( i = 0; i <= QSCENEMAXCOUNT; i++ )
	{
		QScene -> Scene[ i ] = malloc ( sizeof ( struct _scene));
	}
	//�������� ���������� �� ������� � �� �������� ����������
	//TODO: �����, ��� ����� ���������� �������� � ������������ ���������� ������, ��� ��� ��������� �� ���������������-
	//����
	{
		Q.ErrorSend = &_ErrorSend;
		Q.ErrorRead = &_ErrorRead;
		
		Q.WindowCreate = &_WindowCreate;
		Q.WindowDestroy = &_WindowDestroy;
		Q.WindowRender = &_WindowRender;
		
		Q.AppFlags = &_AppFlags;
		
		Q.EventUpdate = &_EventUpdate;
		Q.EventKey = &_EventKey; 
		
		Q.ImageLoad = &_ImageLoad;
		Q.ImageDraw = &_ImageDraw;
		
		Q.SceneCreate = &_SceneCreate;
		Q.SceneActive = &_SceneActive;
		
	}
	
	//���������� ��������� ���������
	Q.AppFlags (QWINDOWFLAG, QSET, QOPENGL);
	Q.AppFlags (QRENDERFLAG, QSET, QHARDWARE);
	
	//�������������� ������� ����
	QScene -> SceneCount = 0;
	//���� ������������� SDL �� �������...
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		//... �� ����������� ������������ �� ������...
		Q.ErrorSend(Q.ErrorRead(0));
		//...� �������� ��������� ����������
		QQuit();
	}
}

void QQuit( )
{
	
}

Uint32 _AppFlags( int type, int subtype, ... )
{
	/* ������� ��������� ���������� ��� ���� � ������� */ 
	
	//���� ������� �������������� ���������
	va_list fparam;
	va_start ( fparam, subtype);
	Uint32 param = va_arg(fparam, Uint32 );
	va_end(fparam);
	//������� ��� �������
	switch ( type )
	{
		//���� ��� - QWINDOWFLAG
		case 0x00:
			//�������� ������� ���������
			QWindow -> WindowFlags = ( Uint32 ) NULL;
			//������� ������
			switch ( subtype )
			{
				//���� ������ - QSET
				case 0x02:
					//������������� ��������
					QWindow -> WindowFlags = param;
				break;
				//���� ������ - QGET
				case 0x03:
					//���������� ��� ���������
					return (QWindow -> WindowFlags);
				break;
			}
		break;
		//���� ��� - QRENDERFLAG
		case 0x01:
			//�������� ������� ���������
			QWindow -> RenderFlags = ( Uint32 ) NULL;
			//������� ������
			switch ( subtype )
			{
				//���� ������ - QSET
				case 0x02:
					//������������� ��������
					QWindow -> RenderFlags = param;
				break;
				//���� ������ - QGET
				case 0x03:
					//���������� ��� ���������
					return (QWindow -> RenderFlags);
				break;
			}
		break;
		
	}
}
