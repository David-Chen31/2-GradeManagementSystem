#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "StructualBody.h"
#include "GetInformationFromID.h"


const wchar_t* getclassname(wchar_t stu_number[])//已将char型修改为wchar_t型 根据学号获取班级中文名 打印用
{
	int class_code = ClassGet(stu_number);
	const wchar_t* class_names[9] =
	{
		L"1班", L"2班", L"3班", L"4班",L"5班",L"6班",L"7班",L"8班",L"9班"
	};
	if (class_code >= 1 && class_code <= 9)
	{
		return class_names[class_code - 1];
	}
	else
	{
		return L"未知班级";
	}
}
const wchar_t* getcollegename(wchar_t stu_number[])//已将char型修改为wchar_t型 根据学号获取学院中文名 打印用
{
	int college_code = CollegeGet(stu_number);
	const wchar_t* college_names[12] =
	{
		L"动物医学学院", L"地球科学学院", L"体育学院", L"法学院", L"哲学与社会学院",
		L"公共外交学院", L"建设工程学院", L"外国语学院", L"汽车工程学院",
		L"临床医学院", L"计算机科学与技术学院", L"软件学院"
	};
	if (college_code >= 1 && college_code <= 12)
	{
		return college_names[college_code - 1];
	}
	else
	{
		return L"未知学院";
	}
}
const wchar_t* getgradename(wchar_t stu_number[])//已将char型修改为wchar_t型 根据学号获取年级中文名 打印用
{
	int grade_code = GradeGet(stu_number);
	const wchar_t* grade_names[4] =
	{
		L"2023级", L"2022级", L"2021级", L"2020级"
	};
	if (grade_code >= 20 && grade_code <= 23)
	{
		return grade_names[23 - grade_code];
	}
	else
	{
		return L"未知年级";
	}
}