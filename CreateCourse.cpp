#include "Header.h"

bool course_is_exist(Year*& pHead, int& n, char* year, char* semester, char* course)
{
	char dirD[] = "20/yearData";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, year);
	strcat(c, "/");
	strcat(c, semester);
	strcat(c, "/courses.txt");

	ifstream fcin;
	fcin.open(c);
	fcin >> n;
	int check = n;
	if (check == 0)
    {
		fcin.close();
		return false;
	}
	else {
		Year* pCur = pHead;
		while (check > 0)
		{
			if (pHead == nullptr)
			{
				pHead = new Year();
				char c[15];
				fcin.ignore();
				fcin.get(c, 15, '\n');
				pHead->coursesData = new char[strlen(c) + 1];
				strcpy(pHead->coursesData, c);
				pCur = pHead;
				pHead->pNext = nullptr;
			}
			else
			{
				pCur->pNext = new Year();
				pCur = pCur->pNext;
				char c[15];
				fcin.ignore();
				fcin.get(c, 15, '\n');
				pCur->coursesData = new char[strlen(c) + 1];
				strcpy(pCur->coursesData, c);
				pCur->pNext = nullptr;
			}
			check--;
		}
		fcin.close();
		pCur = pHead;
		while (pCur)
        {
			if (strcmp(pCur->coursesData, course) == 0)
				return true;
			pCur = pCur->pNext;
		}
		return false;
	}
}


void createNewCourse(Year* pHead, int &n, char* year, char* semester, char* course)
{
    char direct[] = "20/yearData/";
    char c[500] = "";
    strcat(c, direct);
    strcat(c, year);
    strcat(c, "/");
	strcat(c, semester);
	strcat(c, "/courses.txt");

	ofstream fcout;
	fcout.open(c);

	Year* pCur = pHead;
	n += 1;
	fcout << n << endl;

	if (pHead == nullptr) {
		pHead = new Year;
		pHead->coursesData = course;
		pHead->pNext = nullptr;
		fcout << pHead->courseData;
	}
	else {
		while (pCur) {
			fout << pCur->coursesData << endl;
			pCur = pCur->pNext;
		}
		pCur = new Year;
		pCur->coursesData = course;
		fout << pCur->coursesData;
		pCur->pNext = nullptr;
	}
	fcout.close();

	char e[500] = "";
	strcat(e, dirD);
	strcat(e, year);
	strcat(e, "\\");
	strcat(e, semester);
	strcat(e, "\\");
	strcat(e, className);
	CreateDirectoryA(e, NULL);
}
