#include "Header/Q.h"

void _ErrorSend( char* Error )
{
	/* ������� �������� ��������� � ����� ������ */
	
	//���������� ������ � �������
	//TODO: ����������� ���������� ��������� � �������, ���� ��� ����
	printf ("Error: %s\n", Error);
}

char* _ErrorRead( int ErrorCode )
{
	/* ������� ��������� ������ �� �� ���� */
	
	//C������ �������� �� ������� ������
	switch( ErrorCode )
	{
		//���� 0...
		case 0: 
			//...������ �� ������������� SDL
			return Q_ERROR_SDL_INIT;
		break;
	}
}
