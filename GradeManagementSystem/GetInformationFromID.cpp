#include "StructualBody.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

int GradeGet(wchar_t stu_number[])//ͨ��ѧ�Ż�ȡ�꼶
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
int ClassGet(wchar_t stu_number[])//ͨ��ѧ�Ż�ȡ�༶
{
	return (int)stu_number[5];
}
int CollegeGet(wchar_t stu_number[])//ͨ��ѧ�Ż�ȡѧԺ
{
	return ((int)stu_number[0]) * 10 + (int)stu_number[1];
}