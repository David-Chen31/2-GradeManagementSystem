#include "StructualBody.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

GRA* SeekGrade(GRA* sentinel, int grade)
{
	struct Grade* co_grade = sentinel->next;//co_grade代表第一个学院节点
	while (co_grade != NULL)
	{
		if (co_grade->GradeName == grade)

			break;
		else
			co_grade = co_grade->next;
	}
	return co_grade;
}//此函数用于根据用户输入的年级号查找对应年级,且若未能在链表中查找到返回空指针
COL* SeekCollege(GRA* sentinel, int grade, int college)
{
	struct Grade* co_grade = SeekGrade(sentinel, grade);//先查找所在年级,co_grade 代表已找到的年级

	struct College* co_college = co_grade->colList;//co_college代表第一个学院节点
	while (co_college != NULL)
	{
		if (co_college->CollegeName == college)
			break;
		else
			co_college = co_college->next;
	}
	return co_college;
}//此函数用于根据用户输入的学院号查找对应学院,且若未能在链表中查找到返回空指针


CLA* SeekClass(GRA* sentinel, int grade, int college, int Class)
{
	struct Grade* co_grade = SeekGrade(sentinel, grade);//查找所在年级,co_grade 代表已找到的年级
	struct College* co_college = SeekCollege(sentinel, grade, college);//查找所在学院,co_college 代表已找到的学院
	struct Class* co_class = co_college->classList;//co_class代表第一个班级节点
	while (co_class != NULL)
	{
		if (co_class->ClassName == Class)
			break;
		else
			co_class = co_class->next;
	}
	return co_class;
}//此函数用于根据用户输入的班级号查找对应班级,且若未能在链表中查找到返回空指针