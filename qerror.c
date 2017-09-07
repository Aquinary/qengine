#include "Header/Q.h"

void _ErrorSend( char* Error )
{
	/* Функция отправки сообщения в среду вывода */
	
	//Отправляем ошибку в консоль
	//TODO: Возможность отправлять сообщения в консоль, файл или окно
	printf ("Error: %s\n", Error);
}

char* _ErrorRead( int ErrorCode )
{
	/* Функция получения ошибки по ее коду */
	
	//Cлушаем параметр на наличие ошибок
	switch( ErrorCode )
	{
		//Если 0...
		case 0: 
			//...ошибка об инициализации SDL
			return Q_ERROR_SDL_INIT;
		break;
	}
}
