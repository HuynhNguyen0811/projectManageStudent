#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <time.h>  
#include <string>
#include <fstream>
using namespace std;

struct Date {
	int Day, Month, Year;
};

struct Student {
	int No;
	unsigned long long Student_ID;
	string FirstName;
	string LastName;
	bool Gender;
	Date Date_Of_Birth;
	unsigned long long Social_ID;
};

struct Course {
	unsigned long long Course_ID;
	string Course_Name;
	string Teacher_Name;
	int Number_Of_Credits;
	int MaxStu;
};

void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int compareDate(Date x, Date y) {
	if (x.Year < y.Year || x.Month < y.Month || x.Day < y.Day) return 1; //dayx  < dayy
	else if (x.Year == y.Year && x.Month == y.Month && x.Day == y.Day) return 0; //dayx = dayy
	else return -1; //dayx > dayy
}

int isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return 29;
	}
	else {
		return 28;
	}
}

//void readFileStudent(string path, )

unsigned long long calculateDate(Date x) {
	unsigned long long seconds = 0;
	int tempMonth = isLeapYear(x.Year);
	switch (x.Month) {
	case 1: seconds = (unsigned long long) x.Day; break;
	case 2: seconds = (unsigned long long) 31 + x.Day; break;
	case 3: seconds = (unsigned long long) tempMonth + 31 + x.Day; break;
	case 4: seconds = (unsigned long long) 31 + tempMonth + 31 + x.Day; break;
	case 5: seconds = (unsigned long long) 30 + 31 + tempMonth + 31 + x.Day; break;
	case 6: seconds = (unsigned long long) 31 + 30 + 31 + tempMonth + 31 + x.Day; break;
	case 7: seconds = (unsigned long long) 30 + 31 + 30 + 31 + tempMonth + 31 + x.Day; break;
	case 8: seconds = (unsigned long long) 31 + 30 + 31 + 30 + 31 + tempMonth + 31 + x.Day; break;
	case 9: seconds = (unsigned long long) 31 + 31 + 30 + 31 + 30 + 31 + tempMonth + 31 + x.Day; break;
	case 10: seconds = (unsigned long long) 30 + 31 + 31 + 30 + 31 + 30 + 31 + tempMonth + 31 + x.Day; break;
	case 11: seconds = (unsigned long long) 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31 + tempMonth + 31 + x.Day; break;
	case 12: seconds = (unsigned long long) 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31 + tempMonth + 31 + x.Day; break;
	}
	seconds += (unsigned long long) ((unsigned long long) x.Year - 2000) * 365;
	int temp = x.Year;
	while (temp > 2000) {
		if (isLeapYear(temp) == 29) seconds++;
		temp -= 1;
	}
	return seconds * 86400;
}

void createSemester() {


}

void AtTheBeginningOfSemester() {
	int* flag = new int;
	cout << "Choose:\n1. Create semester\n2. Create a course registration\n3. Add a course\n4. View list of courses\n5. Update course infomation\n6. Delete course";
	cin >> *flag;
	switch (*flag) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	}
	delete flag;
}

unsigned long long takeTime() {
	time_t timer;
	struct tm y2k = { 0 };
	unsigned long long seconds;

	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

	time(&timer);  /* get current time; same as: timer = time(NULL)  */

	seconds = difftime(timer, mktime(&y2k));
	return seconds;
}

int main()
{
	Date date{ 24, 3, 2021 };
	cout << takeTime() - calculateDate(date);
	return 0;
}