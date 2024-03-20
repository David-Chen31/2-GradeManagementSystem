#include "StructualBody.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

GRA* SeekGrade(GRA* sentinel, int grade)
{
	struct Grade* co_grade = sentinel->next;//co_grade�����һ��ѧԺ�ڵ�
	while (co_grade != NULL)
	{
		if (co_grade->GradeName == grade)

			break;
		else
			co_grade = co_grade->next;
	}
	return co_grade;
}//�˺������ڸ����û�������꼶�Ų��Ҷ�Ӧ�꼶,����δ���������в��ҵ����ؿ�ָ��
COL* SeekCollege(GRA* sentinel, int grade, int college)
{
	struct Grade* co_grade = SeekGrade(sentinel, grade);//�Ȳ��������꼶,co_grade �������ҵ����꼶

	struct College* co_college = co_grade->colList;//co_college�����һ��ѧԺ�ڵ�
	while (co_college != NULL)
	{
		if (co_college->CollegeName == college)
			break;
		else
			co_college = co_college->next;
	}
	return co_college;
}//�˺������ڸ����û������ѧԺ�Ų��Ҷ�ӦѧԺ,����δ���������в��ҵ����ؿ�ָ��


CLA* SeekClass(GRA* sentinel, int grade, int college, int Class)
{
	struct Grade* co_grade = SeekGrade(sentinel, grade);//���������꼶,co_grade �������ҵ����꼶
	struct College* co_college = SeekCollege(sentinel, grade, college);//��������ѧԺ,co_college �������ҵ���ѧԺ
	struct Class* co_class = co_college->classList;//co_class�����һ���༶�ڵ�
	while (co_class != NULL)
	{
		if (co_class->ClassName == Class)
			break;
		else
			co_class = co_class->next;
	}
	return co_class;
}//�˺������ڸ����û�����İ༶�Ų��Ҷ�Ӧ�༶,����δ���������в��ҵ����ؿ�ָ��