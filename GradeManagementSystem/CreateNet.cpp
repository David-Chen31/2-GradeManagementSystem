#include "StructualBody.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "SearchStudent.h"
#include "ReadFileToList.h"
#include "IfExist.h"
#include "GetInformationFromID.h"

//年级、学院、班级名确定用int型是吗

double GPA(double mark)
{
	double gpa;
	if (mark < 60)
		gpa = 0;
	else if (mark >= 60 && mark < 64)
		gpa = 1;
	else if (mark >= 64 && mark < 67)
		gpa = 1.3;
	else if (mark >= 67 && mark < 70)
		gpa = 1.7;
	else if (mark >= 70 && mark < 74)
		gpa = 2;
	else if (mark >= 74 && mark < 77)
		gpa = 2.3;
	else if (mark >= 77 && mark < 80)
		gpa = 2.7;
	else if (mark >= 80 && mark < 84)
		gpa = 3;
	else if (mark >= 84 && mark < 87)
		gpa = 3.3;
	else if (mark >= 87 && mark < 90)
		gpa = 3.7;
	else if (mark >= 90 && mark <= 100)
		gpa = 4;
	return gpa;
}



//建立最前面的哨兵节点
GRA* CreateSentinelNode()
{
	GRA* sentinel = (GRA*)malloc(sizeof(GRA));
	if (sentinel == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	sentinel->next = NULL;
	return sentinel;
}


//建一个班级
CLA* CreateClassNode(int name)
{
	CLA* NewClass = (CLA*)malloc(sizeof(CLA));
	if (NewClass == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	NewClass->ClassName = name;
	NewClass->studentList = NULL;
	NewClass->next = NULL;
	return NewClass;
}

//建一个学院
COL* CreateCollegeNode(int name)
{
	COL* NewCollege = (COL*)malloc(sizeof(COL));
	if (NewCollege == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	NewCollege->CollegeName = name;
	NewCollege->classList = NULL;
	NewCollege->next = NULL;
	return NewCollege;
}

//建立一个年级
GRA* CreateGradeNode(int name)
{
	GRA* NewGrade = (GRA*)malloc(sizeof(GRA));
	if (NewGrade == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	NewGrade->GradeName = name;
	NewGrade->colList = NULL;
	NewGrade->next = NULL;
	return NewGrade;
}

//初始化课程名和课程分数绩点排名
void InitializeStudentMarks(STU* student)
{
	wchar_t course_names[5][32] = {
		L"专业课", L"基础课1", L"基础课2", L"通识课1", L"通识课2"
	};

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			wcscpy(student->Mark[i][j].StuCoursename, course_names[j]);//把课程名决定了
			student->Mark[i][j].StuMark = -1;//把分数和排名初始化为-1
			student->Mark[i][j].StuRank = -1;
			student->Mark[i][j].StuGpa = GPA(student->Mark[i][j].StuMark);
		}
	}
}

//把每年级每学院每班的 学生链表 插入到大链表中
void InsertStudentList(GRA* Sentinel)
{
	int gra = 1, term = 1, col = 1, cla = 1, num = 1;
	GRA* pgra = Sentinel;
	COL* pcol = pgra->colList;
	CLA* pcla = pcol->classList;
	STU* pstu = NULL, * StuSentinel = NULL;
	for (; gra <= 4; gra++)
	{
		for (; col <= 12; col++)
		{
			while (IfClassExist(gra, col, cla))//判断是否有这个班级
			{
				StuSentinel = ReadFileToStuNode(gra, col, cla, num++);//读入第一个学生，并把此学生作为头指针
				pcla->studentList = StuSentinel;//头指针被班级连接
				while (IfStudentExist(gra, col, cla, num))//循环判断是否有这个学生，把一个班的同学读入链表
				{
					pstu = ReadFileToStuNode(gra, col, cla, num++);
					StuSentinel->next = pstu;
					StuSentinel = pstu;
				}
				pcla = pcla->next;//读下一个班
			}
			pcol = pcol->next;//读下一个学院
		}
		pgra = pgra->next;//读下一个年级
	}
}

//按照每年级每学院已有班级数目，建立对应个数结点的班级链表
CLA* CreateCLassList(int gra, int col)
{
	int num = 1;
	CLA* classSentinel = CreateClassNode(num++);
	CLA* pclassnew = NULL, * pclasscurrent = classSentinel;
	while (IfClassExist(gra, col, num))
	{
		pclassnew = CreateClassNode(num++);
		pclasscurrent->next = pclassnew;
		pclasscurrent = pclassnew;
	}
}

//把每年级每学院的班级链表 插入到对应学院指针下
void InsertClassList(GRA* Sentinel)
{
	GRA* current = Sentinel;
	COL* pcol = NULL;
	CLA* pcla = NULL;
	for (int gra = 1; gra <= 4; gra++)
	{
		for (int col = 1; col <= 12; col++)
		{
			pcol = current->colList;
			pcla = CreateCLassList(gra, col);
			pcol->classList = pcla;
			pcol = pcol->next;
		}
		current = current->next;
	}
}

//建12个学院
COL* CreateCollegeList()
{
	COL* collegelist = NULL;
	COL* collegecur = NULL;
	int collegename[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };//collegename：1-12
	for (int i = 0; i < 12; i++)
	{
		COL* newcollege = CreateCollegeNode(collegename[i]);
		newcollege->classList = NULL;
		if (collegelist == NULL)
		{
			collegelist = newcollege;
			collegecur = newcollege;
		}
		else
		{
			collegecur->next = newcollege;
			collegecur = newcollege;
		}
	}
	return collegelist;
}

//建四个年级
GRA* CreateGradeList()
{
	GRA* current = CreateSentinelNode();
	GRA* sentinel = current;
	int gradename[4] = { 23,22,21,20 };//gradename由2023、2022、2021、2020改成了23、22、21、20
	for (int i = 0; i < 4; i++)
	{
		GRA* newgrade = CreateGradeNode(gradename[i]);
		current->next = newgrade;
		newgrade->colList = CreateCollegeList();
		current = newgrade;
	}
	return sentinel;
}

//创建大链表
GRA* CreateNet()
{
	GRA* Sentinel = CreateGradeList();
	InsertClassList(Sentinel);
	InsertStudentList(Sentinel);
}



struct data_char* create_information(struct data_char* w, wchar_t stu_number[9])
{
	struct data_char* p = NULL;
	p = (struct data_char*)malloc(sizeof(struct data_char));
	wcscpy((p->Stu_Number), stu_number);
	p->next = NULL;
	w->next = p;
	return p;
}//此链表用于存储姓名相同的学生的学号


void collegeExchange(wchar_t stu_number[], GRA* sentinel, int college)//转专业 转入学院已知
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	int grade = GradeGet(stu_number);
	DeleteStudent(stu_number, sentinel);
	COL* newcollege = SeekCollege(sentinel, grade, college);
	CLA* currentClass = newcollege->classList;
	while (currentClass->next != NULL)
	{
		currentClass = currentClass->next;
	}
	int Class = currentClass->ClassName;
	STU* newstudent = addStudent(grade, college, Class, sentinel);
	wchar_t newstudentnumber[9];
	wcscpy(newstudentnumber, newstudent->StuNumber);
	*newstudent = *specific;
	wcscpy(newstudent->StuNumber, newstudentnumber);// 转专业的学生综合绩点的排名要不要变 ？不变或变：与现有学院的人比？/变为-1
	for (int i = 0; i < 10; i++)//素质类项目加分的改变
	{
		ContestBonus(stu_number, sentinel, i, newstudent->Contest[i].ContestLevel, newstudent->Contest[i].ContestPrecedentRank);
		ProjectBonus(stu_number, sentinel, newstudent->Project[i].ProjectPrecedentOrSecond, i);
		PaperBonus(stu_number, sentinel, newstudent->Paper[i].PaperLevel, newstudent->Paper[i].IfPaperPrecedent, i);
	}
}