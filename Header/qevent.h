#ifndef QEVENT_H
#define QEVENT_H

//TODO: ������������� �������� ��� ������� �� ����� QKEY_*

struct _qevent
{
	SDL_Event Event;
	Uint8 KeyCodeDown;
	Uint8 KeyCodeUp;
	const Uint8 *KeyState;
} *QEvent;

void _EventUpdate( void );
int _EventKey( int, Uint8, ... );
#endif

