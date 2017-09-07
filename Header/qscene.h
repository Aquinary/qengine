#ifndef QSCENE_H
#define QSCENE_H
//Структура-тип
typedef struct __scene
{
	int ID; //Идентификатор сцены
	int LSize; //Логический размер
	int ZLevel; //Пложения слоя
	int Active; //Активность сцены
} _Scene;

struct _qscene
{
	//_Scene *Scene[ QSCENEMAXCOUNT ];
	struct _scene
	{
		int ID; //Идентификатор сцены
		int LSize; //Логический размер
		int ZLevel; //Пложения слоя
		int Active; //Активность сцены
	} *Scene [ QSCENEMAXCOUNT ];
	int SceneCount; //Число сцен
} *QScene;
void _SceneCreate ( int, int, int);
int _SceneActive ( int );
#endif

