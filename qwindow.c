#include "Header/Q.h"

void _WindowCreate( char* Caption, int X, int Y, int W, int H)
{
	/* Функция создания окна */                                                                                                                                                                                                    
	
	//Присваеваем параметры 
	QWindow -> Caption = Caption;
	QWindow -> X = X;
	QWindow -> Y = Y;
	QWindow -> W = W;
	QWindow -> H = H;
	//Создаем окно
	QWindow -> Window = SDL_CreateWindow
	( 
		QWindow -> Caption, 
		QWindow -> X, 
		QWindow -> Y,
		QWindow -> W,
		QWindow -> H,
		QWindow -> WindowFlags
	);
	//Создание области рендера
	QWindow -> Render = SDL_CreateRenderer 
	(
		QWindow -> Window,
		-1,
		QWindow -> RenderFlags
	);
}

void _WindowDestroy ( )
{
	/* Функция уничтожения окна */
	SDL_DestroyWindow ( QWindow -> Window );
}

void _WindowRender ( )
{
	/* Функция очистки и обновления изображения */
	SDL_RenderPresent ( QWindow -> Render); 
	SDL_RenderClear ( QWindow -> Render );
}

void _WindowMaximize ( )
{
	/* Функция максимизации окна */
	
}

void _WindowMinimize ( )
{
	/* Функция минимизации окна */
	
}

char* _WindowCaption ( int Type, ... )
{
	/* Функции установки/получения заголовка окна */
	
}
