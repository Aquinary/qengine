#include "Header/Q.h"

void _EventUpdate ()
{
	/* Функция прослушки событий, поступающих извне */
	
	//Слушаем 
	while ( SDL_PollEvent( &QEvent -> Event ))
	{
		//Слушаем тип события для QKEYHOLD
		QEvent -> KeyState = SDL_GetKeyboardState(NULL);
		//Слушаем тип события
		switch ( QEvent -> Event.type )
		{
			//Если "Выход"
			case SDL_QUIT:
				//Выходим
				//TODO: Реализовать встроенную функцию
				exit (0);
			break;
			//Если "Кнопка опушена вниз
			case SDL_KEYDOWN:
				//Присваеваем временной переменной значение опущеной кнопки
				QEvent -> KeyCodeDown = ( Uint8 ) QEvent -> Event.key.keysym.sym;
				//Присваем временной переменной для обработки QKEYHOLD событий
				QEvent -> KeyState = ( Uint8 ) QEvent -> Event.key.keysym.sym;
			break;
			//Если "Кнопка отпущена
			case SDL_KEYUP:
				//Присваеваем временной переменной значение опущеной кнопки
				QEvent -> KeyCodeUp = ( Uint8 ) QEvent -> Event.key.keysym.sym;
			break;
			default:
			break;
		}
	}
}


