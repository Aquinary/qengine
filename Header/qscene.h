#ifndef QSCENE_H
#define QSCENE_H
//���������-���
typedef struct __scene
{
	int ID; //������������� �����
	int LSize; //���������� ������
	int ZLevel; //�������� ����
	int Active; //���������� �����
} _Scene;

struct _qscene
{
	//_Scene *Scene[ QSCENEMAXCOUNT ];
	struct _scene
	{
		int ID; //������������� �����
		int LSize; //���������� ������
		int ZLevel; //�������� ����
		int Active; //���������� �����
	} *Scene [ QSCENEMAXCOUNT ];
	int SceneCount; //����� ����
} *QScene;
void _SceneCreate ( int, int, int);
int _SceneActive ( int );
#endif

