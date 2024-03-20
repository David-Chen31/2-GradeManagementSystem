#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "StructualBody.h"
#include "Locale.h"



int NumberOfClass(int grade, int college, GRA* sentinel)//�༶��������
{
	COL* Specific = SeekCollege(sentinel, grade, college);
	if (Specific != NULL)
	{
		// classList��һ��ָ��༶�����ָ������
		int count = 0;
		CLA* currentClass = Specific->classList;
		while (currentClass != NULL)
		{
			count++;
			currentClass = currentClass->next;
		}
		return count;
	}
	else
	{
		// ����δ�ҵ��ض�ѧԺ�����
		return 0;
	}
}
int NumberOfStudent(int Class, int grade, int college, GRA* sentinel)//ѧ����������
{
	CLA* Specific = SeekClass(sentinel, grade, college, Class);
	if (Specific != NULL)
	{
		// studentList��һ��ָ��ѧ�������ָ������
		int count = 0;
		STU* currentStudent = Specific->studentList;
		while (currentStudent != NULL)
		{
			count++;
			currentStudent = currentStudent->next;
		}
		return count;
	}
	else
	{
		// ����δ�ҵ��ض��༶�����
		return 0;
	}
}