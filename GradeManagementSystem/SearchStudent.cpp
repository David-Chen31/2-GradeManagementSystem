#include "StructualBody.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "Locale.h"
#include "TransformNumToChar.h"


/*
* 如何释放
*/

STU* SeekStudentByID(wchar_t stu_number[], GRA* sentinel)
{
	int grade_number = GradeGet(stu_number);//获得年级号
	int college_number = CollegeGet(stu_number);//获得学院号
	int class_number = ClassGet(stu_number);//获得班级号

	struct Grade* co_grade = SeekGrade(sentinel, grade_number);//查找所在年级,co_grade 代表已找到的年级
	struct College* co_college = SeekCollege(sentinel, grade_number, college_number);//查找所在学院,co_college 代表已找到的学院
	struct Class* co_class = SeekClass(sentinel, grade_number, college_number, class_number);//查找所在班级,co_class 代表已找到的班级

	struct Student* co_student = co_class->studentList;//co_student代表第一个学生节点
	while (co_student != NULL)
	{
		if (wcscmp(co_student->StuNumber, stu_number) == 0)
			break;
		else
			co_student = co_student->next;
	}
	return co_student;
}//此函数用于根据用户输入的学号查找对应学生,且若未能在链表中查找到返回空指针  //记得释放链表

struct  data_char* SeekStudentByName(wchar_t stu_name[], GRA* sentinel)
{
	struct Grade* co_grade = sentinel->next;
	struct College* co_college = co_grade->colList;
	struct Class* co_class = co_college->classList;
	struct Student* co_student = co_class->studentList;
	int n = 0;//用来记录学生个数
	struct data_char* stu_head = NULL, * stu_now = NULL, * stu_copy = NULL;

	for (co_grade = sentinel->next; co_grade != NULL; co_grade = co_grade->next)
	{
		for (co_college = co_grade->colList; co_college != NULL; co_college = co_college->next)
		{
			for (co_class = co_college->classList; co_class != NULL; co_class = co_class->next)
			{
				for (co_student = co_class->studentList; co_student != NULL; co_student = co_student->next)
				{
					if (wcscmp(co_student->StuName, stu_name) == 0)
					{
						if (n == 0)
						{
							struct data_char* stu_head = (struct data_char*)malloc(sizeof(struct data_char));
							wcscpy((stu_head->Stu_Number), (co_student->StuNumber));
							stu_head->next = NULL;
							stu_copy = stu_head;
							n++;
						}//创建第一个节点
						else
						{
							struct data_char* stu_now = (struct data_char*)malloc(sizeof(struct data_char));
							wcscpy((stu_now->Stu_Number), (co_student->StuNumber));
							stu_now->next = NULL;
							stu_copy->next = stu_now;
							stu_copy = stu_now;
							n++;
						}
					}
					else
						co_student = co_student->next;
				}
			}
		}
	}
	return stu_head;
}//此函数用于根据用户输入的姓名查找对应学生,返回存储学生学号的链表首节点(无哨兵节点),且若未能在链表中查找到返回空指针

