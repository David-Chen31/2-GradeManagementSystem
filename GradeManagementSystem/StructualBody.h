#ifndef CIRCLE_I
#define CIRCLE_I



double GPA(double mark);
char FileAddress[80] = "D:/VisualStudio/Code/GradeManagementSystem/JluScore/1-1/1/08.txt";



//�ɼ�
typedef struct Mark
{
	wchar_t StuCoursename[32];
	double StuMark;
	double StuGpa;
	long long StuRank;
}MARK;

//����
typedef struct Paper
{
	int IfPaperPrecedent;
	wchar_t PaperName[32];
	wchar_t PaperTime[32];
	wchar_t PaperNumeber[32];
	wchar_t PaperLevel[32];
	double PaperBonus;
}PAP;

//��Ŀ
typedef struct Project
{
	int ProjectPrecedentOrSecond;
	wchar_t ProjectName[32];
	wchar_t ProjectTeacher_name[32];
	wchar_t ProjectNumber[32];
	wchar_t ProjectBegintime[32];
	wchar_t ProjectFinishtime[32];
	double ProjectBonus;
}PRO;


//����
typedef struct contest
{
	int ContestPrecedentRank;
	wchar_t ContestName[32];
	wchar_t ContestHost[32];
	wchar_t ContestTime[32];
	wchar_t ContestLevel[32];
	double ContestBonus;
}CON;

//ѧ��
typedef struct Student
{
	wchar_t StuName[32];

	int TestNumber;

	//082310
	//����ѧ��ʶ�� ѧԺ=stu_number[0]*10+stu_number[1] 08
	//�꼶=2000+stu_number[2]*10+stu_number[3] 23
	//�༶=stu_number[4]*10+stu_number[5]   10
	wchar_t StuNumber[9];

	long long ComprehensiveRank[8];

	double ComprehensiveGpa[8];




	//Mark[][0]-רҵ�� Mark[][1]-������1 
	//Mark[][2]-������2 Mark[][3]-ͨʶ��1 Mark[][4]-ͨʶ��2
	MARK Mark[8][5];

	PAP Paper[10];

	PRO Project[10];

	CON Contest[10];

	struct Student* next;
}STU;


//!�½ṹ���ѧ�� Ϊ�����Һ���!
struct data_char
{
	wchar_t Stu_Number[9];
	struct data_char* next;
};

//�༶
typedef struct Class
{
	int ClassName;
	STU* studentList;
	struct Class* next;
}CLA;

//ѧԺ
typedef struct College
{
	int CollegeName;
	CLA* classList;
	struct College* next;
}COL;

//�꼶
typedef struct Grade
{
	int GradeName;
	COL* colList;
	struct Grade* next;
}GRA;

#endif