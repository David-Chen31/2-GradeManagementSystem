#ifndef CIRCLE_J
#define CIRCLE_J
#include "StructualBody.h"

void changestuName(wchar_t stu_number[], GRA* sentinel, wchar_t newName[]);//改学生姓名

void changePaperName(wchar_t stu_number[], GRA* sentinel, wchar_t newName[], int numberofpaper);//改论文名
void changePaperPrecedent(wchar_t stu_number[], GRA* sentinel, int numberofpaper, int precedent);//改论文是否一作
void changePaperLevel(wchar_t stu_number[], GRA* sentinel, int numberofpaper, wchar_t level[]);//改论文等级
void changePaperNumber(wchar_t stu_number[], GRA* sentinel, int numberofpaper, wchar_t number[]);//改论文页码数
void changePaperTime(wchar_t stu_number[], GRA* sentinel, int numberofpaper, wchar_t time[]);//改论文发表时间

void changeProjectName(wchar_t stu_number[], GRA* sentinel, wchar_t newName[], int numberofproject);//改项目名
void changeProjectPrecedent(wchar_t stu_number[], GRA* sentinel, int numberofproject, int precedent);//改项目负责人还是第二名
void changeProjectTeachername(wchar_t stu_number[], GRA* sentinel, wchar_t teachername[], int numberofproject);//改项目指导老师名
void changeProjectNumber(wchar_t stu_number[], GRA* sentinel, int numberofproject, wchar_t number[]);//改项目编号
void changeProjectBegintime(wchar_t stu_number[], GRA* sentinel, int numberofproject, wchar_t begintime[]);//改立项时间
void changeProjectFinishtime(wchar_t stu_number[], GRA* sentinel, int numberofproject, wchar_t finishtime[]);//改结项时间

void changeContestName(wchar_t stu_number[], GRA* sentinel, wchar_t newName[], int numberofcontest);//改竞赛名称
void changeContestPrecedent(wchar_t stu_number[], GRA* sentinel, int numberofcontest, int precedent);//改获奖人位次
void changeContestLevel(wchar_t stu_number[], GRA* sentinel, int numberofcontest, wchar_t level[]);//改获奖等级
void changeContestHost(wchar_t stu_number[], GRA* sentinel, int numberofcontest, wchar_t host[]);//改主办单位
void changeContestTime(wchar_t stu_number[], GRA* sentinel, int numberofcontest, wchar_t time[]);//改获奖时间

void changeMark(wchar_t stu_number[], GRA* sentinel, int semester, int course);//改某次考试课程分数


#endif