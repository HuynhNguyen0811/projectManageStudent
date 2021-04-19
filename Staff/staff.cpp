#include "staff.h"
#include "commonFunc.h"
void inputFromKeyboardCourse(_course*& pHead) {
	_course* pCur = nullptr;
	int temp = -1, check;
	wchar_t a = '\n';
	while (temp != 0) {
		if (pHead == nullptr) {
			pHead = new _course;
			pCur = pHead;
		}
		else {
			pCur->pNext = new _course;
			pCur = pCur->pNext;
		}

		cout << "Course's ID: ";
		cin >> pCur->data.courseId;

		cin.ignore(1000, '\n');

		_LText();

		wcout << "Course's name: ";
		std::getline(wcin, pCur->data.courseName, L'\n');
		wcout << "Teacher's name: ";
		std::getline(wcin, pCur->data.teacherName, L'\n');

		_SText();
		cout << "Number of credits: ";
		cin >> pCur->data.credit;
		cout << "Do you want to change course's max student (default as 50, enter 1 to change): ";
		cin >> check;
		if (check == 1) {
			cout << "Credit: ";
			cin >> pCur->data.credit;
		}

		pCur->data.session = new session[2];
		for (int i = 0; i < 2; i++) {
			pCur->data.session[i].dayOfWeek = new wchar_t[3 + 1];
			pCur->data.session[i].hour = new wchar_t[2 + 1];
		}

		for (int i = 0; i < 2; i++) {
			cout << "Day of week " << i + 1 << " of the course will performed (MON / TUE / WED / THU / FRI / SAT): ";
			wcin >> pCur->data.session[i].dayOfWeek;
			pCur->data.session[i].dayOfWeek[3] = '\0';
			cout << "The session " << i + 1 << " of the course will performed (S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30)): ";
			wcin >> pCur->data.session[i].hour;
			pCur->data.session[i].hour[2] = '\0';
		}
		string temp;
		cout << "Start registration date: "; cin >> temp; pCur->data.startRegis = stringToDate(temp);
		cout << "End registration date: "; cin >> temp; pCur->data.endRegis = stringToDate(temp);

		pCur->pNext = nullptr;

		cout << "Enter 0 to stop: ";
		cin >> temp;
	}

	pCur->pNext = new _course;
	pCur = pCur->pNext;
	pCur->data.session = new session[2];
	for (int i = 0; i < 2; i++) {
		pCur->data.session[i].dayOfWeek = new wchar_t[3 + 1];
		pCur->data.session[i].hour = new wchar_t[2 + 1];
	}
	pCur->pNext = nullptr;
	void readAllIndividualCourseFile(string path, _course * pHead) {
		while (pHead != nullptr && pHead->pNext != nullptr) {
			readIndividualCourseFile(path + to_string(pHead->data.courseId) + ".csv", pHead);
			pHead = pHead->pNext;
		}
	}

	void readIndividualCourseFile(string path, _course * pHead) { //to read id student that regis
		wifstream fileIn;
		fileIn.open(path, ios_base::in);
		fileIn.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::generate_header>));

		wstring temp;
		_studentRegis* pCur = nullptr;
		while (fileIn) {
			if (pHead->data.studentID == nullptr) {
				pHead->data.studentID = new _studentRegis;
				pCur = pHead->data.studentID;
			}
			else {
				pCur->pNext = new _studentRegis;
				pCur = pCur->pNext;
			}
			fileIn.ignore(1000, '\n');
			getline(fileIn, temp, L',');
			pCur->data = wstringToLong(temp);
			pCur->pNext = nullptr;
		}

		fileIn.close();
	}

	void writeCourseFile(string path, _course * pHead) {
		if (pHead == nullptr) return;
		wofstream fileOut;
		fileOut.open(path, ios_base::out);
		fileOut.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::generate_header>));

		while (pHead->pNext != nullptr) {
			fileOut << pHead->data.courseId << "," << pHead->data.courseName << "," << pHead->data.teacherName << "," << pHead->data.credit << "," << pHead->data.maxStu << ",";
			fileOut << pHead->data.session[0].dayOfWeek << "," << pHead->data.session[0].hour << ",";
			fileOut << pHead->data.session[1].dayOfWeek << "," << pHead->data.session[1].hour << ",";
			fileOut << pHead->data.startRegis.day << L"/" << pHead->data.startRegis.month << L"/" << pHead->data.startRegis.year << ",";
			fileOut << pHead->data.endRegis.day << L"/" << pHead->data.endRegis.month << L"/" << pHead->data.endRegis.year << endl;
			pHead = pHead->pNext;
		}

		fileOut.close();
	}

	void writeIndividualCourseFile(string path, course pHead) {
		wofstream fileOut;
		fileOut.open(path, ios_base::out);
		fileOut.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::generate_header>));

		fileOut << pHead.courseId << "," << pHead.courseName << "," << pHead.teacherName << "," << pHead.credit << "," << pHead.maxStu << ",";
		fileOut << pHead.session[0].dayOfWeek << "," << pHead.session[0].hour << ",";
		fileOut << pHead.session[1].dayOfWeek << "," << pHead.session[1].hour << ",";
		fileOut << pHead.startRegis.day << L"/" << pHead.startRegis.month << L"/" << pHead.startRegis.year << ",";
		fileOut << pHead.endRegis.day << L"/" << pHead.endRegis.month << L"/" << pHead.endRegis.year << endl;

		_studentRegis* pCur = pHead.studentID;
		while (pCur != nullptr && pCur->pNext != nullptr) {
			fileOut << pCur->data << endl;
			pCur = pCur->pNext;
		}

		fileOut.close();
	}