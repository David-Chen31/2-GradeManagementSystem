#include "StructualBody.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "Locale.h"
#include "CreateNet.h"

void DeleteClass(int grade, int college, int Class, GRA* sentinel)
{
	//ɾ�༶ �����
}
void DeleteStudent(wchar_t stu_number[], GRA* sentinel)
{
	//ɾѧ�� �����
}


STU* addStudent(int grade, int college, int Class, GRA* sentinel)//��ѧ��
{
	CLA* specific = SeekClass(sentinel, grade, college, Class);
	STU* StudentToBeAdded = (STU*)malloc(sizeof(STU));
	if (StudentToBeAdded == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	STU* current = specific->studentList;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = StudentToBeAdded;
	wcscpy(StudentToBeAdded->StuNumber, current->StuNumber);
	int xuhao = ((int)current->StuNumber[6]) * 10 + (int)current->StuNumber[7];
	StudentToBeAdded->StuNumber[6] = (wchar_t)((xuhao + 1) / 10);
	StudentToBeAdded->StuNumber[7] = (wchar_t)((xuhao + 1) % 10);//����ѧ����ʱ���ʼ��ѧ��ѧ��
	InitializeStudentMarks(StudentToBeAdded);//����ѧ����ʱ���ʼ���γ̳ɼ���Ϣ
	StudentToBeAdded->next = NULL;
	return StudentToBeAdded;
}//����

CLA* addClass(int grade, int college, GRA* sentinel)//�Ӱ༶
{
	COL* specific = SeekCollege(sentinel, grade, college);
	CLA* ClassToBeAdded = (CLA*)malloc(sizeof(CLA));
	if (ClassToBeAdded == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	CLA* current = specific->classList;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = ClassToBeAdded;
	ClassToBeAdded->ClassName = current->ClassName + 1;//���Ӱ༶��ʱ��ֻ��ʼ�����
	ClassToBeAdded->next = NULL;
	return ClassToBeAdded;
}