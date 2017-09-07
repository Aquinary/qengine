#include "Header/Q.h"

void _EventUpdate ()
{
	/* ������� ��������� �������, ����������� ����� */
	
	//������� 
	while ( SDL_PollEvent( &QEvent -> Event ))
	{
		//������� ��� ������� ��� QKEYHOLD
		QEvent -> KeyState = SDL_GetKeyboardState(NULL);
		//������� ��� �������
		switch ( QEvent -> Event.type )
		{
			//���� "�����"
			case SDL_QUIT:
				//�������
				//TODO: ����������� ���������� �������
				exit (0);
			break;
			//���� "������ ������� ����
			case SDL_KEYDOWN:
				//����������� ��������� ���������� �������� �������� ������
				QEvent -> KeyCodeDown = ( Uint8 ) QEvent -> Event.key.keysym.sym;
				//�������� ��������� ���������� ��� ��������� QKEYHOLD �������
				QEvent -> KeyState = ( Uint8 ) QEvent -> Event.key.keysym.sym;
			break;
			//���� "������ ��������
			case SDL_KEYUP:
				//����������� ��������� ���������� �������� �������� ������
				QEvent -> KeyCodeUp = ( Uint8 ) QEvent -> Event.key.keysym.sym;
			break;
			default:
			break;
		}
	}
}


