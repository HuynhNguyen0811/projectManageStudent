#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <time.h>  
#include <string>
#include <fstream>
#include <filesystem>
using namespace std;

struct Date {
	int Day, Month, Year;
};

struct Student {
	string No;
	string Student_ID;
	string FirstName;
	string LastName;
	string Gender;
	string Date_Of_Birth;
	string Social_ID;

	double GPA = 0;
};

struct NodeStudent {
	Student data;
	NodeStudent* pNext;
};

struct SchoolYear {
	int x;
	int y;
};

struct Course {
	string Course_ID;
	string Course_Name;
	string Teacher_Name;
	int Number_Of_Credits;
	int MaxStu;
};