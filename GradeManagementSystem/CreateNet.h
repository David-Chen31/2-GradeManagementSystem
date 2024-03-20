#ifndef CIRCLE_B
#define CIRCLE_B
#include "StructualBody.h"

GRA* CreateSentinelNode();
GRA* CreateGradeNode(int name);
COL* CreateCollegeNode(int name);
CLA* CreateClassNode(int name);
STU* CreateStudentNode(wchar_t name[], int num[], int testnum, long long comrank[], double comgpa[]);
CLA* CreateClassList();
COL* CreateCollegeList();
GRA* CreateGradeList();
void InitializeStudentMarks(STU* student);

const char* get_college_name(int college_code);
const char* get_grade_name(int grade_code);



#endif





