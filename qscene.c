#include "Header/Q.h"

void _SceneCreate ( int id, int logical_size, int zlevel)
{
	/* ������� �������� ����� */
	//�������� ��������� ��������� �����
	
	//������� ����� �����
	QScene -> Scene [ id ] -> ID = id; //������������� �����
	QScene -> Scene [ id ] -> LSize = logical_size; //���������� ������ �����
	QScene -> Scene [ id ] -> ZLevel = zlevel; //������� �����. �� ������ �������� 
	QScene -> Scene [ id ] -> Active = 0; //���������� �����
	QScene -> SceneCount += id; //����������� ������� ����. 
	//TODO: ^����� ���� ��������, ����, ����. ������� ����� 1 � ����� 5: � ����� ������ ���� �� ������
	//�� ������ �����
	//FIX: �������� � ���������� �������� id �����.
}

int _SceneActive ( int id )
{
	/* ������� ��������� ������ ����� */
	//���������� ����� �������� �����, ���� id = -1
	if ( id == -1) 
	{	
		int *i = malloc (sizeof (int)); //�������� ������ ��� ���������
		for( *i = 0; *i <= QScene -> SceneCount; (*i)++ )
		{
			//��������� ���������� �����
			if ( QScene -> Scene [ *i ] -> Active == 1 ) 
			{ 
				int t = *i;
				free(i); 
				return t; //���������� ����� �������� �����
			
			}
		}
		
	}
	//�������� ���������� ���� ����
	int *i = malloc (sizeof (int));
	for( *i = 0; *i <= QScene -> SceneCount; (*i)++ )
	{
		QScene -> Scene [ *i ] -> Active = 0;
	}
	free(i);
	//���������� ������ �����
	QScene -> Scene [ id ] -> Active = 1;
}

void _SceneDepth ( int id, int type, ... )
{
	/* ������� ����� ������ ������� ����� */
}

void _SceneDestroy (int id)
{
	/*������� ����������� ����� */
}
