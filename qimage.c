#include "Header/Q.h"

//TODO: ������� �������� ����������� ���� � ������, ���� � ����������
void _ImageLoad ( int id, char* path)
{
	/* ������� �������� ����������� � ������ */
	//�������� ������ �����������
	//���� ���� ��������� OpenGL
	if ( QWindow -> WindowFlags == QOPENGL)
	{
		//�� ������ ��������� ����������� � ������� �������
		//��������� ����������
		SDL_Texture *temp = NULL;
		//��������� ����������� � ������������ ��� � ��������
		temp = IMG_LoadTexture ( QWindow -> Render, path);
		//����������� ����������� ������� ����������� ��������
		QImage -> Texture [ id ] = temp;
		free(temp);
		//TODO: return ������������ ���: ���������� �����������
	} else
	//���� ��� ��������� OpenGL
	if ( QWindow -> WindowFlags != QOPENGL )
	{
		//�� ������ ��������� ����������� � ������� �����������
		//TODO: ��������
//		SDL_Surface *temp = NULL;
//		SDL_Surface *load = NULL;
//		load = IMG_Load ( QWindow -> Render, path);
//		temp = SDL_ConvertSurface ( load, QWindow -> Surface -> format, NULL );
	}
}

void _ImageDraw ( int scene, int id, int w, int h, int x, int y)
{
	/* ������� ������ ����������� �� ����������� */
	//������� ������� ������� ��� �������
	SDL_Rect *rect = malloc ( sizeof ( SDL_Rect ));
	rect -> x = x;
	rect -> y = y;
	rect -> w = w;
	rect -> h = h;
	int *i = malloc (sizeof (int));
	for( *i = 0; *i <= QScene -> SceneCount; (*i)++ )
	{
		//���������, ����� ����� �� ������ ������ �������
		if ( QScene -> Scene [ *i ] -> Active == 1 )
		{
			//������� ����������� � ����
			SDL_RenderCopy ( QWindow -> Render, QImage -> Texture [ id ], NULL, rect); 
		}
	}
	free(i);
	
	
	//����������� ������� ������
	free( rect );
}
