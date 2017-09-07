#include "Header/Q.h"

void _SceneCreate ( int id, int logical_size, int zlevel)
{
	/* Функция создания сцены */
	//Получить последнюю созданную сцену
	
	//Создать новую сцену
	QScene -> Scene [ id ] -> ID = id; //идентификатор сцены
	QScene -> Scene [ id ] -> LSize = logical_size; //логический размер сцены
	QScene -> Scene [ id ] -> ZLevel = zlevel; //глубина сцены. не нужный параметр 
	QScene -> Scene [ id ] -> Active = 0; //активность сцены
	QScene -> SceneCount += id; //увеличиваем счетчик сцен. 
	//TODO: ^могут быть проблемы, если, напр. создана сцена 1 и сцена 5: в таком случае цикл не дойдет
	//до нужной сцены
	//FIX: прибавка к количеству счетчика id сцены.
}

int _SceneActive ( int id )
{
	/* Функция активации нужной сцены */
	//Возвращаем номер активной сцены, если id = -1
	if ( id == -1) 
	{	
		int *i = malloc (sizeof (int)); //выделяем память под указатель
		for( *i = 0; *i <= QScene -> SceneCount; (*i)++ )
		{
			//Проверяем активность сцены
			if ( QScene -> Scene [ *i ] -> Active == 1 ) 
			{ 
				int t = *i;
				free(i); 
				return t; //возвращаем номер активной сцены
			
			}
		}
		
	}
	//Обнуляем активность всех сцен
	int *i = malloc (sizeof (int));
	for( *i = 0; *i <= QScene -> SceneCount; (*i)++ )
	{
		QScene -> Scene [ *i ] -> Active = 0;
	}
	free(i);
	//Активируем нужную сцену
	QScene -> Scene [ id ] -> Active = 1;
}

void _SceneDepth ( int id, int type, ... )
{
	/* Функция смены уровня глубины сцены */
}

void _SceneDestroy (int id)
{
	/*Функция уничтожения сцены */
}
