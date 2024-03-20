#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "StructualBody.h"
#include "GetInformationFromID.h"


const wchar_t* getclassname(wchar_t stu_number[])//�ѽ�char���޸�Ϊwchar_t�� ����ѧ�Ż�ȡ�༶������ ��ӡ��
{
	int class_code = ClassGet(stu_number);
	const wchar_t* class_names[9] =
	{
		L"1��", L"2��", L"3��", L"4��",L"5��",L"6��",L"7��",L"8��",L"9��"
	};
	if (class_code >= 1 && class_code <= 9)
	{
		return class_names[class_code - 1];
	}
	else
	{
		return L"δ֪�༶";
	}
}
const wchar_t* getcollegename(wchar_t stu_number[])//�ѽ�char���޸�Ϊwchar_t�� ����ѧ�Ż�ȡѧԺ������ ��ӡ��
{
	int college_code = CollegeGet(stu_number);
	const wchar_t* college_names[12] =
	{
		L"����ҽѧѧԺ", L"�����ѧѧԺ", L"����ѧԺ", L"��ѧԺ", L"��ѧ�����ѧԺ",
		L"�����⽻ѧԺ", L"���蹤��ѧԺ", L"�����ѧԺ", L"��������ѧԺ",
		L"�ٴ�ҽѧԺ", L"�������ѧ�뼼��ѧԺ", L"���ѧԺ"
	};
	if (college_code >= 1 && college_code <= 12)
	{
		return college_names[college_code - 1];
	}
	else
	{
		return L"δ֪ѧԺ";
	}
}
const wchar_t* getgradename(wchar_t stu_number[])//�ѽ�char���޸�Ϊwchar_t�� ����ѧ�Ż�ȡ�꼶������ ��ӡ��
{
	int grade_code = GradeGet(stu_number);
	const wchar_t* grade_names[4] =
	{
		L"2023��", L"2022��", L"2021��", L"2020��"
	};
	if (grade_code >= 20 && grade_code <= 23)
	{
		return grade_names[23 - grade_code];
	}
	else
	{
		return L"δ֪�꼶";
	}
}