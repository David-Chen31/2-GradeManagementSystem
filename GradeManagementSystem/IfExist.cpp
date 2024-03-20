#include <stdio.h>
#include "ReadFileToList.h"
#include "StructualBody.h"

bool IfClassExist(int gra, int col,int cla)
{
	STU* pstu = NULL;
	pstu = ReadFileToStuNode(gra, col, cla, 1);
	if (pstu == NULL)
		return false;
	else return true;
}

bool IfStudentExist(int gra, int col, int cla, int num)
{
	STU* pstu = NULL;
	pstu = ReadFileToStuNode(gra, col, cla, num);
	if (pstu == NULL)
		return false;
	else return true;
}