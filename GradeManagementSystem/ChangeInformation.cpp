#include <stdio.h>
#include <wchar.h>
#include "StructualBody.h"
#include "SearchStudent.h"
#include "GetInformationFromID.h"

//学生学号是查询的基础，不能改变（转专业另外考虑，已改变学号），进而学院班级年级也不变
//只剩下能改变素质类项目、成绩、学生姓名

void changestuName(wchar_t stu_number[], GRA* sentinel, wchar_t newName[])//改学生姓名
{
	STU* specific = SeekStudentByID(stu_number, sentinel);//每个改的函数都是先通过学生学号找到学生所在的节点，同下
	wcscpy(specific->StuName, newName);
}


void changePaperName(wchar_t stu_number[], GRA* sentinel, wchar_t newName[], int numberofpaper)//改论文名
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Paper[numberofpaper - 1].PaperName, newName);
}
void changePaperPrecedent(wchar_t stu_number[], GRA* sentinel, int numberofpaper, int precedent)//改论文是否一作
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	specific->Paper[numberofpaper - 1].IfPaperPrecedent = precedent;
}
void changePaperLevel(wchar_t stu_number[], GRA* sentinel, int numberofpaper, wchar_t level[])//改论文等级
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Paper[numberofpaper - 1].PaperLevel, level);
}
void changePaperNumber(wchar_t stu_number[], GRA* sentinel, int numberofpaper, wchar_t number[])//改论文页码数
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Paper[numberofpaper - 1].PaperNumeber, number);
}
void changePaperTime(wchar_t stu_number[], GRA* sentinel, int numberofpaper, wchar_t time[])//改论文发表时间
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Paper[numberofpaper - 1].PaperTime, time);
}

//待改
//void PaperBonus(wchar_t stu_number[], GRA* sentinel, wchar_t level[], int precedent, int numberofpaper)
//{
//	int college = CollegeGet(stu_number);
//	//已知学生的学院int college、论文是否一作int precedent、论文等级wchar_t level[]、需要修改第几篇论文int numberofpaper，陈恩导入文件操作得到对应的int bonus
//	STU* specific = SeekStudentByID(stu_number, sentinel);
//	specific->Paper[numberofpaper - 1].PaperBonus = bonus;
//}//论文加分随着学院、论文是否一作、论文等级的改变而改变，不能手动改变
////改论文加分=论文信息变化后调用论文加分的函数




void changeProjectName(wchar_t stu_number[], GRA* sentinel, wchar_t newName[], int numberofproject)//改项目名
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Project[numberofproject - 1].ProjectName, newName);
}
void changeProjectPrecedent(wchar_t stu_number[], GRA* sentinel, int numberofproject, int precedent)//改项目负责人还是第二名
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	specific->Project[numberofproject - 1].ProjectPrecedentOrSecond = precedent;
}
void changeProjectTeachername(wchar_t stu_number[], GRA* sentinel, wchar_t teachername[], int numberofproject)//改项目指导老师名
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Project[numberofproject - 1].ProjectTeacher_name, teachername);
}
void changeProjectNumber(wchar_t stu_number[], GRA* sentinel, int numberofproject, wchar_t number[])//改项目编号
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Project[numberofproject - 1].ProjectNumber, number);
}
void changeProjectBegintime(wchar_t stu_number[], GRA* sentinel, int numberofproject, wchar_t begintime[])//改立项时间
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Project[numberofproject - 1].ProjectBegintime, begintime);
}
void changeProjectFinishtime(wchar_t stu_number[], GRA* sentinel, int numberofproject, wchar_t finishtime[])//改结项时间
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Project[numberofproject - 1].ProjectBegintime, finishtime);
}

//待改
//void ProjectBonus(wchar_t stu_number[], GRA* sentinel, int precedent, int numberofproject)
//{
//	int college = CollegeGet(stu_number);
//	//已知学生的学院int college、项目是负责人还是第二名int precedent、需要修改第几个项目int numberofproject，陈恩导入文件操作得到对应的int bonus
//	STU* specific = SeekStudentByID(stu_number, sentinel);
//	specific->Project[numberofproject - 1].ProjectBonus = bonus;
//}//项目加分随着学院、项目是负责人还是第二名的改变而改变，不能手动改变
////改项目加分=项目信息变化后调用项目加分的函数


void changeContestName(wchar_t stu_number[], GRA* sentinel, wchar_t newName[], int numberofcontest)//改竞赛名称
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Contest[numberofcontest - 1].ContestName, newName);
}
void changeContestPrecedent(wchar_t stu_number[], GRA* sentinel, int numberofcontest, int precedent)//改获奖人位次
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	specific->Contest[numberofcontest - 1].ContestPrecedentRank = precedent;
}
void changeContestLevel(wchar_t stu_number[], GRA* sentinel, int numberofcontest, wchar_t level[])//改获奖等级
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Contest[numberofcontest - 1].ContestLevel, level);
}
void changeContestHost(wchar_t stu_number[], GRA* sentinel, int numberofcontest, wchar_t host[])//改主办单位
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Contest[numberofcontest - 1].ContestHost, host);
}
void changeContestTime(wchar_t stu_number[], GRA* sentinel, int numberofcontest, wchar_t time[])//改获奖时间
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	wcscpy(specific->Contest[numberofcontest - 1].ContestTime, time);
}

//void ContestBonus(wchar_t stu_number[], GRA* sentinel, int numberofcontest, wchar_t level[], int precedent)
//{
//	int college = CollegeGet(stu_number);
//	//已知学生的学院int college、比赛人员的排位顺序是否是前六名int precedent、需要修改第几个比赛int numberofcontest、比赛奖项wchar_t level[]，陈恩导入文件操作得到对应的int bonus
//	STU* specific = SeekStudentByID(stu_number, sentinel);
//	specific->Contest[numberofcontest - 1].ContestBonus = bonus;
//}//获奖加分随着学院、比赛人员的排位顺序是否是前六名、比赛奖项的改变而改变，不能手动改变
////改获奖加分=获奖信息变化后调用获奖加分的函数


void changeMark(wchar_t stu_number[], GRA* sentinel, int semester, int course)//改某次考试课程分数
{
	STU* specific = SeekStudentByID(stu_number, sentinel);
	specific->Mark[semester][course].StuMark;
	specific->Mark[semester][course].StuGpa = GPA(specific->Mark[semester][course].StuMark);
}
//综合绩点和综合排名随着素质类加分和成绩的改变而改变，单科成绩排名随成绩的改变而改变
// 所以这里不能手动改变。到时写一个计算综合绩点和排序的函数填入
