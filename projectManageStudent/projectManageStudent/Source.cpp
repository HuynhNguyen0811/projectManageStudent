#include "Header.h"

unsigned long long takeTime();

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

void menuStudent() {

}

void menuStaff() {

}

void createSchoolYear(SchoolYear &sy) {
	sy.x = sy.y = 0;
	int i = 2000;
	unsigned long long current = takeTime();
	while (sy.x == 0) {
		Date date { 1, 9, i };
		if (calculateDate(date) > current) {
			sy.x = i;
			sy.y = i + 1;
		}
		i++;
	}
}
void deleteList(NodeStudent*& pHead) {
	NodeStudent* pTmp = pHead;
	while (pHead != nullptr) {
		pHead = pHead->pNext;
		delete pTmp;
		pTmp = pHead;
	}
}

void readFileStudent(string& path, NodeStudent *&pHead) {
	cout << "Please enter the name of the file you want to input: ";
	cin >> path;
	ifstream fileIn;
	fileIn.open(path + ".csv", ios_base::in);

	if (fileIn.fail())
	{
		cout << "File is not existed" << endl;
		readFileStudent(path, pHead);
	}

	NodeStudent* pCur = nullptr;
	string temp;

	while (fileIn) {
		if (pHead == nullptr) {
			pHead = new NodeStudent;
			pCur = pHead;
		}
		else {
			pCur->pNext = new NodeStudent;
			pCur = pCur->pNext;
		}
		//fileIn >> pCur->data.No;
		//cout << pCur->data.No;
		getline(fileIn, pCur->data.No, ',');
		//pCur->data.No = atoi(temp);
		getline(fileIn, pCur->data.Student_ID, ',');
		getline(fileIn, pCur->data.FirstName, ',');
		getline(fileIn, pCur->data.LastName, ',');
		getline(fileIn, pCur->data.Gender, ',');
		getline(fileIn, pCur->data.Date_Of_Birth, ',');
		fileIn >> pCur->data.Social_ID;
		pCur->pNext = nullptr;
	}

	fileIn.close();
}

void writeFileStudent(string path, NodeStudent* pHead) {
	ofstream fileOut;
	fileOut.open(path + ".csv", ios_base::out);
	while (pHead != nullptr) {
		fileOut << pHead->data.No << "," << pHead->data.Student_ID << "," << pHead->data.FirstName << "," << pHead->data.LastName << "," << pHead->data.Gender << "," << pHead->data.Date_Of_Birth << "," << pHead->data.Social_ID << endl;
		pHead = pHead->pNext;
	}
	fileOut.close();
}

void createLogInStudent(string path, NodeStudent* pHead) {
	ofstream fileOut;
	fileOut.open(path + ".csv", ios_base::app);
	while (pHead != nullptr) {
		fileOut << pHead->data.Student_ID << "," << 1 << endl;
		pHead = pHead->pNext;
	}
	fileOut.close();
}

void createClassList(string className, SchoolYear sy) {
	ofstream fileOut;
	fileOut.open(to_string(sy.x) + "-" + to_string(sy.y) + (string) "year1ClassName" + ".csv", ios_base::app);

	fileOut << className << endl;
	
	
	fileOut.close();
}

void AtTheBeginningOfSchoolYear() {
	system("CLS");
	SchoolYear sy;
	NodeStudent* pHead = nullptr;
	string className;
	createSchoolYear(sy);
	cout << "Creating a school year (" << sy.x << "-" << sy.y << ")" << endl;
	while (true) {
		int temp;
		cout << "Input '0' if you want to escape: ";
		cin >> temp;
		if (temp == 0) {
			system("CLS");
			break;
		}
		cout << "Creating a class:\nPlease enter class name: ";
		cin >> className;
		createClassList(className, sy);
		string path, newPath;
		readFileStudent(path, pHead);
		createLogInStudent("passStudent", pHead);
		//newPath = to_string(sem.x) + "-" + to_string(sem.y) + className;
		//rename(path + ".csv", newPath + ".csv");
		writeFileStudent(to_string(sy.x) + "-" + to_string(sy.y) + "year1" + className, pHead);
		deleteList(pHead);
	}
	menuStaff();
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
	string a, b; int c, d;
	Date date{ 26, 3, 2021 };
	NodeStudent* pHead = nullptr;
	SchoolYear sy;
	cout << takeTime() - calculateDate(date) << endl;

	createSchoolYear(sy);

	cout << sy.x << "-" << sy.y;

	AtTheBeginningOfSchoolYear();

	/*ofstream f;
	f.open("abc.txt", ios_base::out);

	
	//while (!f.eof());


	for (int i = 0; i < 10; i++) {
		f << i << endl;
	}
	//f << 50;


	f.close();
	
	cout << endl;
	ifstream f2;
	f2.open("github.csv");
	for (int i = 0; i < 10; i++) {
		f2 >> c;
		getline(f2, b, ',');
		f2 >> d;
		getline(f2, b, '\n');
		cout << c  <<  " " << d << endl;
	}
	f2.close();*/

	return 0;
}