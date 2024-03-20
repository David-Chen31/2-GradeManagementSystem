#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "StructualBody.h"
#include "Locale.h"



int NumberOfClass(int grade, int college, GRA* sentinel)//班级结点的数量
{
	COL* Specific = SeekCollege(sentinel, grade, college);
	if (Specific != NULL)
	{
		// classList是一个指向班级对象的指针数组
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
		// 处理未找到特定学院的情况
		return 0;
	}
}
int NumberOfStudent(int Class, int grade, int college, GRA* sentinel)//学生结点的数量
{
	CLA* Specific = SeekClass(sentinel, grade, college, Class);
	if (Specific != NULL)
	{
		// studentList是一个指向学生对象的指针数组
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
		// 处理未找到特定班级的情况
		return 0;
	}
}