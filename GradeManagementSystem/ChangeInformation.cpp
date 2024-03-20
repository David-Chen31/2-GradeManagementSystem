#include <stdio.h>
#include <wchar.h>
#include "StructualBody.h"
#include "SearchStudent.h"
#include "GetInformationFromID.h"

//ѧ��ѧ���ǲ�ѯ�Ļ��������ܸı䣨תרҵ���⿼�ǣ��Ѹı�ѧ�ţ�������ѧԺ�༶�꼶Ҳ����
//ֻʣ���ܸı���������Ŀ���ɼ���ѧ������

void changestuName(wchar_t stu_number[], GRA* sentinel, wchar_t newName[])//��ѧ������
{
	STU* specific = SeekStudentByID(stu_number, sentinel);//ÿ���ĵĺ���������ͨ��ѧ��ѧ���ҵ�ѧ�����ڵĽڵ㣬ͬ��
	wcscpy(specific->StuName, newName);
}


void changePaperName(wchar_t stu_number[], GRA* sentinel, wchar_t newName[], int numberofpaper)//��������
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Paper[numberofpaper - 1].PaperName, newName);
}
void changePaperPrecedent(wchar_t stu_number[], GRA* sentinel, int numberofpaper, int precedent)//�������Ƿ�һ��
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	specific->Paper[numberofpaper - 1].IfPaperPrecedent = precedent;
}
void changePaperLevel(wchar_t stu_number[], GRA* sentinel, int numberofpaper, wchar_t level[])//�����ĵȼ�
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Paper[numberofpaper - 1].PaperLevel, level);
}
void changePaperNumber(wchar_t stu_number[], GRA* sentinel, int numberofpaper, wchar_t number[])//������ҳ����
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Paper[numberofpaper - 1].PaperNumeber, number);
}
void changePaperTime(wchar_t stu_number[], GRA* sentinel, int numberofpaper, wchar_t time[])//�����ķ���ʱ��
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Paper[numberofpaper - 1].PaperTime, time);
}

//����
//void PaperBonus(wchar_t stu_number[], GRA* sentinel, wchar_t level[], int precedent, int numberofpaper)
//{
//	int college = CollegeGet(stu_number);
//	//��֪ѧ����ѧԺint college�������Ƿ�һ��int precedent�����ĵȼ�wchar_t level[]����Ҫ�޸ĵڼ�ƪ����int numberofpaper���¶������ļ������õ���Ӧ��int bonus
//	STU* specific = SeekStudentByID(stu_number, sentinel);
//	specific->Paper[numberofpaper - 1].PaperBonus = bonus;
//}//���ļӷ�����ѧԺ�������Ƿ�һ�������ĵȼ��ĸı���ı䣬�����ֶ��ı�
////�����ļӷ�=������Ϣ�仯��������ļӷֵĺ���




void changeProjectName(wchar_t stu_number[], GRA* sentinel, wchar_t newName[], int numberofproject)//����Ŀ��
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Project[numberofproject - 1].ProjectName, newName);
}
void changeProjectPrecedent(wchar_t stu_number[], GRA* sentinel, int numberofproject, int precedent)//����Ŀ�����˻��ǵڶ���
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	specific->Project[numberofproject - 1].ProjectPrecedentOrSecond = precedent;
}
void changeProjectTeachername(wchar_t stu_number[], GRA* sentinel, wchar_t teachername[], int numberofproject)//����Ŀָ����ʦ��
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Project[numberofproject - 1].ProjectTeacher_name, teachername);
}
void changeProjectNumber(wchar_t stu_number[], GRA* sentinel, int numberofproject, wchar_t number[])//����Ŀ���
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Project[numberofproject - 1].ProjectNumber, number);
}
void changeProjectBegintime(wchar_t stu_number[], GRA* sentinel, int numberofproject, wchar_t begintime[])//������ʱ��
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Project[numberofproject - 1].ProjectBegintime, begintime);
}
void changeProjectFinishtime(wchar_t stu_number[], GRA* sentinel, int numberofproject, wchar_t finishtime[])//�Ľ���ʱ��
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Project[numberofproject - 1].ProjectBegintime, finishtime);
}

//����
//void ProjectBonus(wchar_t stu_number[], GRA* sentinel, int precedent, int numberofproject)
//{
//	int college = CollegeGet(stu_number);
//	//��֪ѧ����ѧԺint college����Ŀ�Ǹ����˻��ǵڶ���int precedent����Ҫ�޸ĵڼ�����Ŀint numberofproject���¶������ļ������õ���Ӧ��int bonus
//	STU* specific = SeekStudentByID(stu_number, sentinel);
//	specific->Project[numberofproject - 1].ProjectBonus = bonus;
//}//��Ŀ�ӷ�����ѧԺ����Ŀ�Ǹ����˻��ǵڶ����ĸı���ı䣬�����ֶ��ı�
////����Ŀ�ӷ�=��Ŀ��Ϣ�仯�������Ŀ�ӷֵĺ���


void changeContestName(wchar_t stu_number[], GRA* sentinel, wchar_t newName[], int numberofcontest)//�ľ�������
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Contest[numberofcontest - 1].ContestName, newName);
}
void changeContestPrecedent(wchar_t stu_number[], GRA* sentinel, int numberofcontest, int precedent)//�Ļ���λ��
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	specific->Contest[numberofcontest - 1].ContestPrecedentRank = precedent;
}
void changeContestLevel(wchar_t stu_number[], GRA* sentinel, int numberofcontest, wchar_t level[])//�Ļ񽱵ȼ�
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Contest[numberofcontest - 1].ContestLevel, level);
}
void changeContestHost(wchar_t stu_number[], GRA* sentinel, int numberofcontest, wchar_t host[])//�����쵥λ
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Contest[numberofcontest - 1].ContestHost, host);
}
void changeContestTime(wchar_t stu_number[], GRA* sentinel, int numberofcontest, wchar_t time[])//�Ļ�ʱ��
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Contest[numberofcontest - 1].ContestTime, time);
}

//void ContestBonus(wchar_t stu_number[], GRA* sentinel, int numberofcontest, wchar_t level[], int precedent)
//{
//	int college = CollegeGet(stu_number);
//	//��֪ѧ����ѧԺint college��������Ա����λ˳���Ƿ���ǰ����int precedent����Ҫ�޸ĵڼ�������int numberofcontest����������wchar_t level[]���¶������ļ������õ���Ӧ��int bonus
//	STU* specific = SeekStudentByID(stu_number, sentinel);
//	specific->Contest[numberofcontest - 1].ContestBonus = bonus;
//}//�񽱼ӷ�����ѧԺ��������Ա����λ˳���Ƿ���ǰ��������������ĸı���ı䣬�����ֶ��ı�
////�Ļ񽱼ӷ�=����Ϣ�仯����û񽱼ӷֵĺ���


void changeMark(wchar_t stu_number[], GRA* sentinel, int semester, int course)//��ĳ�ο��Կγ̷���
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	specific->Mark[semester][course].StuMark;
	specific->Mark[semester][course].StuGpa = GPA(specific->Mark[semester][course].StuMark);
}
//�ۺϼ�����ۺ���������������ӷֺͳɼ��ĸı���ı䣬���Ƴɼ�������ɼ��ĸı���ı�
// �������ﲻ���ֶ��ı䡣��ʱдһ�������ۺϼ��������ĺ�������
