#include "Header/Q.h"

void QInit( )
{
	/* Функция инициализации Q */
	
	//Выделение памяти под внутренние структуры
	QWindow = malloc ( sizeof ( struct _qwindow ));
	QEvent = malloc ( sizeof ( struct _qevent ));
	QImage = malloc ( sizeof ( struct _qimage));
	QScene = malloc ( sizeof ( struct _qscene));
	int i;
	for( i = 0; i <= QSCENEMAXCOUNT; i++ )
	{
		QScene -> Scene[ i ] = malloc ( sizeof ( struct _scene));
	}
	//Линковка указателей на функций к их реальным прототипам
	//TODO: думаю, что могут возникнуть проблемы с неправильным выделением памяти, так как указатели не проинициализиро-
	//ваны
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
	
	//Сбрасываем начальные параметры
	Q.AppFlags (QWINDOWFLAG, QSET, QOPENGL);
	Q.AppFlags (QRENDERFLAG, QSET, QHARDWARE);
	
	//Инициализирцем счетчик сцен
	QScene -> SceneCount = 0;
	//Если инициализация SDL не успешна...
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		//... то уведовмляем пользователя об ошибке...
		Q.ErrorSend(Q.ErrorRead(0));
		//...и аварийно завершаем приложение
		QQuit();
	}
}

void QQuit( )
{
	
}

Uint32 _AppFlags( int type, int subtype, ... )
{
	/* Функция установки аттрибутов для окна и рендера */ 
	
	//Если имеются дополнительные параметры
	va_list fparam;
	va_start ( fparam, subtype);
	Uint32 param = va_arg(fparam, Uint32 );
	va_end(fparam);
	//Слушаем тип события
	switch ( type )
	{
		//Если тип - QWINDOWFLAG
		case 0x00:
			//Обнуляем текущее параметры
			QWindow -> WindowFlags = ( Uint32 ) NULL;
			//Слушаем субтип
			switch ( subtype )
			{
				//Если субтип - QSET
				case 0x02:
					//Устанавливаем параметр
					QWindow -> WindowFlags = param;
				break;
				//Если субтип - QGET
				case 0x03:
					//Возвращаем все параметры
					return (QWindow -> WindowFlags);
				break;
			}
		break;
		//Если тип - QRENDERFLAG
		case 0x01:
			//Обнуляем текущее параметры
			QWindow -> RenderFlags = ( Uint32 ) NULL;
			//Слушаем субтип
			switch ( subtype )
			{
				//Если субтип - QSET
				case 0x02:
					//Устанавливаем параметр
					QWindow -> RenderFlags = param;
				break;
				//Если субтип - QGET
				case 0x03:
					//Возвращаем все параметры
					return (QWindow -> RenderFlags);
				break;
			}
		break;
		
	}
}
