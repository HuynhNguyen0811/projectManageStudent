#include <iostream>

struct date;
struct student;
struct _student;
struct Class;
struct _Class;
struct schoolYear;
struct semester;
struct _semester;
struct session;
struct _session;
struct course;
struct _course;
struct score;
struct _score;
struct account;
struct _account;

struct date {
	int day, month, year;
};

struct student {
	int No;
	unsigned long long Student_ID;
	std::wstring FirstName;
	std::wstring LastName;
	std::wstring Gender;
	date Date_Of_Birth;
	unsigned long long Social_ID;

	_score* score = nullptr;
	_course* course = nullptr;

	double GPA = 0;
};
struct _student {
	student data;
	_student* pNext, * pPrevious;
};

struct Class {
	std::string name;
	_student* studentFirst;
};
struct _Class {
	Class data;
	_Class* pNext, * pPrevious;
};

struct schoolYear {
	int x;
	int y;
};
struct semester {
	schoolYear schoolYear;
	date startDay, endDate;
	_course* course = nullptr;
};
struct _semester {
	semester data;
	_semester* pNext, * pPrevious;
};

struct session {
	std::string dayOfWeek;
	std::string hour;
};
struct _session {
	session data;
	_session* pNext, * pPrevious;
};

struct course {
	unsigned long long courseId;
	std::string courseName;
	std::string teacherName;
	int credit;
	int maxStu = 50;
	_session* session;
};
struct _course {
	course data;
	_course* pNext, * pPrevious;
};

struct score {
	course data;
	double mark;
};
struct _score {
	score data;
	_score* pNext, * pPrevious;
};

struct account {
	unsigned long long Student_ID;
	std::string password;
};
struct _account {
	account data;
	_account* pNext, * pPrevious;
};