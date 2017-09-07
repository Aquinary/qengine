#include "Header/Q.h"

//TODO: функция загрузки изображений либо в индекс, либо в переменную
void _ImageLoad ( int id, char* path)
{
	/* Функция загрузки изображения в иднекс */
	//Проверка режима отображения
	//Если есть поддержка OpenGL
	if ( QWindow -> WindowFlags == QOPENGL)
	{
		//То делаем обработку изображений с помощью текстур
		//Временная переменная
		SDL_Texture *temp = NULL;
		//Загружаем изображение и конвентируем его в текстуру
		temp = IMG_LoadTexture ( QWindow -> Render, path);
		//Присваиваем глабольному массиву изображений текстуру
		QImage -> Texture [ id ] = temp;
		free(temp);
		//TODO: return Возвращаемый тип: полученное изображение
	} else
	//Если нет поддержки OpenGL
	if ( QWindow -> WindowFlags != QOPENGL )
	{
		//То делаем обработку изображений с помощью конвертации
		//TODO: Доделать
//		SDL_Surface *temp = NULL;
//		SDL_Surface *load = NULL;
//		load = IMG_Load ( QWindow -> Render, path);
//		temp = SDL_ConvertSurface ( load, QWindow -> Surface -> format, NULL );
	}
}

void _ImageDraw ( int scene, int id, int w, int h, int x, int y)
{
	/* Функция вывода изображения на поверхность */
	//Создаем базовую область для расчета
	SDL_Rect *rect = malloc ( sizeof ( SDL_Rect ));
	rect -> x = x;
	rect -> y = y;
	rect -> w = w;
	rect -> h = h;
	int *i = malloc (sizeof (int));
	for( *i = 0; *i <= QScene -> SceneCount; (*i)++ )
	{
		//Проверяем, какая сцена на данный момент активна
		if ( QScene -> Scene [ *i ] -> Active == 1 )
		{
			//Выводим изображение в окно
			SDL_RenderCopy ( QWindow -> Render, QImage -> Texture [ id ], NULL, rect); 
		}
	}
	free(i);
	
	
	//Освобождаем занятую память
	free( rect );
}
