#include "StructualBody.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include "Locale.h"
#include "TransformNumToChar.h"


/*
* ����ͷ�
*/

STU* SeekStudentByID(wchar_t stu_number[], GRA* sentinel)
{
	int grade_number = GradeGet(stu_number);//����꼶��
	int college_number = CollegeGet(stu_number);//���ѧԺ��
	int class_number = ClassGet(stu_number);//��ð༶��

	struct Grade* co_grade = SeekGrade(sentinel, grade_number);//���������꼶,co_grade �������ҵ����꼶
	struct College* co_college = SeekCollege(sentinel, grade_number, college_number);//��������ѧԺ,co_college �������ҵ���ѧԺ
	struct Class* co_class = SeekClass(sentinel, grade_number, college_number, class_number);//�������ڰ༶,co_class �������ҵ��İ༶

	struct Student* co_student = co_class->studentList;//co_student�����һ��ѧ���ڵ�
	while (co_student != NULL)
	{
		if (wcscmp(co_student->StuNumber, stu_number) == 0)
			break;
		else
			co_student = co_student->next;
	}
	return co_student;
}//�˺������ڸ����û������ѧ�Ų��Ҷ�Ӧѧ��,����δ���������в��ҵ����ؿ�ָ��  //�ǵ��ͷ�����

struct  data_char* SeekStudentByName(wchar_t stu_name[], GRA* sentinel)
{
	struct Grade* co_grade = sentinel->next;
	struct College* co_college = co_grade->colList;
	struct Class* co_class = co_college->classList;
	struct Student* co_student = co_class->studentList;
	int n = 0;//������¼ѧ������
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
						}//������һ���ڵ�
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
}//�˺������ڸ����û�������������Ҷ�Ӧѧ��,���ش洢ѧ��ѧ�ŵ������׽ڵ�(���ڱ��ڵ�),����δ���������в��ҵ����ؿ�ָ��

