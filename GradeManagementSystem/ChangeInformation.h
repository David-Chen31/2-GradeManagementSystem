#ifndef CIRCLE_J
#define CIRCLE_J
#include "StructualBody.h"

void changestuName(wchar_t stu_number[], GRA* sentinel, wchar_t newName[]);//��ѧ������

void changePaperName(wchar_t stu_number[], GRA* sentinel, wchar_t newName[], int numberofpaper);//��������
void changePaperPrecedent(wchar_t stu_number[], GRA* sentinel, int numberofpaper, int precedent);//�������Ƿ�һ��
void changePaperLevel(wchar_t stu_number[], GRA* sentinel, int numberofpaper, wchar_t level[]);//�����ĵȼ�
void changePaperNumber(wchar_t stu_number[], GRA* sentinel, int numberofpaper, wchar_t number[]);//������ҳ����
void changePaperTime(wchar_t stu_number[], GRA* sentinel, int numberofpaper, wchar_t time[]);//�����ķ���ʱ��

void changeProjectName(wchar_t stu_number[], GRA* sentinel, wchar_t newName[], int numberofproject);//����Ŀ��
void changeProjectPrecedent(wchar_t stu_number[], GRA* sentinel, int numberofproject, int precedent);//����Ŀ�����˻��ǵڶ���
void changeProjectTeachername(wchar_t stu_number[], GRA* sentinel, wchar_t teachername[], int numberofproject);//����Ŀָ����ʦ��
void changeProjectNumber(wchar_t stu_number[], GRA* sentinel, int numberofproject, wchar_t number[]);//����Ŀ���
void changeProjectBegintime(wchar_t stu_number[], GRA* sentinel, int numberofproject, wchar_t begintime[]);//������ʱ��
void changeProjectFinishtime(wchar_t stu_number[], GRA* sentinel, int numberofproject, wchar_t finishtime[]);//�Ľ���ʱ��

void changeContestName(wchar_t stu_number[], GRA* sentinel, wchar_t newName[], int numberofcontest);//�ľ�������
void changeContestPrecedent(wchar_t stu_number[], GRA* sentinel, int numberofcontest, int precedent);//�Ļ���λ��
void changeContestLevel(wchar_t stu_number[], GRA* sentinel, int numberofcontest, wchar_t level[]);//�Ļ񽱵ȼ�
void changeContestHost(wchar_t stu_number[], GRA* sentinel, int numberofcontest, wchar_t host[]);//�����쵥λ
void changeContestTime(wchar_t stu_number[], GRA* sentinel, int numberofcontest, wchar_t time[]);//�Ļ�ʱ��

void changeMark(wchar_t stu_number[], GRA* sentinel, int semester, int course);//��ĳ�ο��Կγ̷���


#endif