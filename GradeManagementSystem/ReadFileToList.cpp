#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <string.h>
#include <malloc.h>

#include "StructualBody.h"
#include "CreateNet.h"




STU* ReadFileToStuNode(int grade, int college ,int classnum ,int id)
{
	setlocale(LC_ALL, "");

	//printf("%c", FileAddress[52]);
	// 字符串F[52]字符对应年级
	// 字符串F[56]字符对应班级
	// 字符串F[58]F[59]字符对应班里第几个

	//FILE* fp = fopen("D:/VisualStudio/Code/GradeManagementSystem/JluScore/1/01/1/01.txt", "r");
	//1，根据 指针、学号 找到对应学生的插入位置
	//2，把学生信息从文件里面 输入到 新建的学生结点上
	//3，把每个学生结点连起来
	//4，把头学生结点返回 使其被班级结点连接

	STU* stu = (STU*)malloc(sizeof(STU));
	stu->next = NULL;

	FileAddress[52] = '0' + grade;
	FileAddress[54] = '0' + college/10;
	FileAddress[55] = '0' + college%10;
	FileAddress[57] = '0' + classnum;
	FileAddress[59] = '0' + id/10;
	FileAddress[60] = '0' + id%10;

	FILE* fp = NULL;
	fp = fopen(FileAddress, "r");
	if (!fp)
	{
		return NULL;
	}

	//读取姓名、学号、考试次数
	fwscanf(fp, L"%ls %ls %d\n", stu->StuName, stu->StuNumber,stu->TestNumber);
	
	//读取综合排名
	for (int i = 0; i < stu->TestNumber-1; i++)
	{
		fscanf(fp, "%lld ", &stu->ComprehensiveRank[i]);
	}
	fscanf(fp, "%lld\n", &stu->ComprehensiveRank[stu->TestNumber - 1]);

	//读取综合绩点
	for (int i = 0; i < stu->TestNumber - 1; i++)
	{
		fscanf(fp, "%lf ", &stu->ComprehensiveGpa[i]);
	}
	fscanf(fp, "%lf\n", &stu->ComprehensiveGpa[stu->TestNumber - 1]);

	//读取成绩,一个学期对应5门课，一门课有三个数据
	InitializeStudentMarks(stu);
	for (int i = 0; i < stu->TestNumber; i++)
	{
		fscanf(fp, "%lf %lf %lld %lf %lf %lld %lf %lf %lld %lf %lf %lld %lf %lf %lld\n",
			&stu->Mark[i][0].StuMark, &stu->Mark[i][0].StuGpa, &stu->Mark[i][0].StuRank,
			&stu->Mark[i][1].StuMark, &stu->Mark[i][1].StuGpa, &stu->Mark[i][1].StuRank,
			&stu->Mark[i][2].StuMark, &stu->Mark[i][2].StuGpa, &stu->Mark[i][2].StuRank,
			&stu->Mark[i][3].StuMark, &stu->Mark[i][3].StuGpa, &stu->Mark[i][3].StuRank,
			&stu->Mark[i][4].StuMark, &stu->Mark[i][4].StuGpa, &stu->Mark[i][4].StuRank,
			&stu->Mark[i][5].StuMark, &stu->Mark[i][5].StuGpa, &stu->Mark[i][5].StuRank);
	}

	wprintf(L"%ls", stu->StuName);

	//读取论文
	char ch = '0';
	int i = 0;
	while (1)
	{
		fscanf(fp, "%c", &ch);
		if (ch == '\n')
			break;
		fseek(fp, -1, SEEK_CUR);
		fwscanf(fp, L"%d %ls %ls %ls %ls %lf\n",
			&stu->Paper[i].IfPaperPrecedent, stu->Paper[i].PaperName, stu->Paper[i].PaperTime, stu->Paper[i].PaperNumeber, stu->Paper[i].PaperLevel, &stu->Paper[i].PaperBonus);
		i++;
	}
	fseek(fp, 10 - i, SEEK_CUR);


	//读取项目
	i = 0;
	while (1)
	{
		fscanf(fp, "%c", &ch);
		if (ch == '\n')
			break;
		fseek(fp, -1, SEEK_CUR);
		fwscanf(fp, L"%d %ls %ls %ls %ls %ls %lf\n",
			&stu->Project[i].ProjectPrecedentOrSecond, stu->Project[i].ProjectName, stu->Project[i].ProjectTeacher_name,
			stu->Project[i].ProjectNumber, stu->Project[i].ProjectBegintime, stu->Project[i].ProjectFinishtime, &stu->Project[i].ProjectBonus);
		i++;
	}
	fseek(fp, 10 - i, SEEK_CUR);


	//读取竞赛
	i = 0;
	while (1)
	{
		fscanf(fp, "%c", &ch);
		if (ch == '\n')
			break;
		fseek(fp, -1, SEEK_CUR);
		fwscanf(fp, L"%d %ls %ls %ls %ls %lf\n",
			&stu->Contest[i].ContestPrecedentRank, stu->Contest[i].ContestHost, stu->Contest[i].ContestTime, 
			stu->Contest[i].ContestLevel, &stu->Contest[i].ContestBonus);
		i++;
	}
	fseek(fp, 10 - i, SEEK_CUR);

	

	return stu;
}




