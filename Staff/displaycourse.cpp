#include "staff.h"
#include "commonFunc.h"
void displayCourseConsole(_course* pHead) {
	_LText();

	while (pHead->pNext != nullptr) {
		wcout << pHead->data.courseId << " ";
		wcout << pHead->data.courseName << " ";
		wcout << pHead->data.teacherName << " ";
		wcout << pHead->data.credit << " ";
		wcout << pHead->data.maxStu << " ";
		wcout << pHead->data.session[0].dayOfWeek << "-" << pHead->data.session[0].hour << " ";
		wcout << pHead->data.session[1].dayOfWeek << "-" << pHead->data.session[1].hour << " ";
		wcout << pHead->data.startRegis.day << L"/" << pHead->data.startRegis.month << L"/" << pHead->data.startRegis.year << " ";
		wcout << pHead->data.endRegis.day << L"/" << pHead->data.endRegis.month << L"/" << pHead->data.endRegis.year << endl;
		pHead = pHead->pNext;
	}

	_SText();
}

void displayIndividualCourseConsole(course pHead) {
	_LText();

	wcout << pHead.courseId << " ";
	wcout << pHead.courseName << " ";
	wcout << pHead.teacherName << " ";
	wcout << pHead.credit << " ";
	wcout << pHead.maxStu << " ";
	wcout << pHead.session[0].dayOfWeek << "-" << pHead.session[0].hour;
	wcout << " ";
	wcout << pHead.session[1].dayOfWeek << "-" << pHead.session[1].hour;
	wcout << " ";
	wcout << pHead.startRegis.day << L"/" << pHead.startRegis.month << L"/" << pHead.startRegis.year << " ";
	wcout << pHead.endRegis.day << L"/" << pHead.endRegis.month << L"/" << pHead.endRegis.year << endl;

	_SText();

	cout << endl;
}

void displayStudentAttendIndividualCourse(_studentRegis* pHead) {
	cout << "Student's ID list: " << endl;
	while (pHead->pNext != nullptr) {
		cout << pHead->data << endl;
		pHead = pHead->pNext;
	}
}
