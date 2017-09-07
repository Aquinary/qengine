#include "Header/Q.h"

int _EventKey( int Type, Uint8 KeyCode, ... )
{
	/* ������� �������� ������� ������� ������� */
	
	
	//���� ������� �������������� ���������
	//TODO: �������� �������, ��� ���. ���������
	//TODO: �������� ���������� ������� ������������ �������, ��� ���������
	//TODO: �������� ����������
	//���������� ��������������� ����
	va_list fparam;
	va_start ( fparam, KeyCode );
	void (*void_func )(void) = va_arg( fparam, void (*) (void));
	void (*int_func )(int) = va_arg( fparam, void (*) (int));
	void (*char_func )(char) = va_arg( fparam, void (*) (char*));
	va_end( fparam );
	//���������� ���������
	va_list farg;
	va_start ( farg, KeyCode );
	int param = va_arg ( farg, void (*) (int));
	va_end(farg);
	
	//������� ���
	switch ( Type )
	{
		//���� ��� - ��������� �������
		case 0x04:
			//� ���� ������� �������
			if ( QEvent -> KeyCodeDown == KeyCode )
			{
				//�� ������������� �� ����
				return 1;	
			}
		break;
		//���� ��� - ��������� �������
		case 0x05:
			//� ���� ������� ��������
			if ( QEvent -> KeyCodeUp == KeyCode )
			{
				//�� ������������� �� ����	
				return 1;
			}
		break;
		//���� ��� - ��������� �������
		case 0x06:
			//TODO: �������������� ������� � ������� ������ ������ ������ �� �� �����������
			if ( QEvent -> KeyState [ SDL_GetScancodeFromKey( KeyCode) ])
			{
				//������������� � �������
				return 1;
			}
		break;
		default:
			//����� ������������� �� ���������� �������
			return 0;
		break;
		
	}
}
