#include "StructualBody.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "Locale.h"
#include "CreateNet.h"

void DeleteClass(int grade, int college, int Class, GRA* sentinel)
{
	//删班级 待填充
}
void DeleteStudent(wchar_t stu_number[], GRA* sentinel)
{
	//删学生 待填充
}


STU* addStudent(int grade, int college, int Class, GRA* sentinel)//加学生
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
	StudentToBeAdded->StuNumber[7] = (wchar_t)((xuhao + 1) % 10);//增加学生的时候初始化学生学号
	InitializeStudentMarks(StudentToBeAdded);//增加学生的时候初始化课程成绩信息
	StudentToBeAdded->next = NULL;
	return StudentToBeAdded;
}//待改

CLA* addClass(int grade, int college, GRA* sentinel)//加班级
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
	ClassToBeAdded->ClassName = current->ClassName + 1;//增加班级的时候只初始化班号
	ClassToBeAdded->next = NULL;
	return ClassToBeAdded;
}