#include "StructualBody.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

int GradeGet(wchar_t stu_number[])//通过学号获取年级
{
	if (stu_number[3] == L'3')
		return 23;
	else if (stu_number[3] == L'2')
		return 22;
	else if (stu_number[3] == L'1')
		return 21;
	else if (stu_number[3] == L'0')
		return 20;
}
int ClassGet(wchar_t stu_number[])//通过学号获取班级
{
	return (int)stu_number[5];
}
int CollegeGet(wchar_t stu_number[])//通过学号获取学院
{
	return ((int)stu_number[0]) * 10 + (int)stu_number[1];
}