#include<string>
#include"Header.h"
#include<iostream>
#include<fstream>
using namespace std;
int stringToInt(string str) {
	int sum = 0;
	for (int i = 1; i <= (sizeof(str) / sizeof(string)); i++) {
		sum *= 10;
		sum += (int)(str[i] - 48);
	}
	return sum;
}

unsigned long long stringToLong(string str) {
	unsigned long long sum = 0;
	for (int i = 1; i <= (sizeof(str) / sizeof(string)); i++) {
		sum *= 10;
		sum += (unsigned long long(str[i]) - 48);
	}
	return sum;
}
void readFileStudent(string& path, NodeStudent*& pHead) {
	cout << " enter file name: ";
	cin >> path;
	ifstream fileIn(path + ".csv");
	if (!fileIn.is_open()) cout << "can not open the file";
	NodeStudent* pCur = pHead;
	string temp;
	fileIn.ignore(1000, char(191));
	getline(fileIn, temp, char(191));
	while (fileIn) {
		if (pHead == nullptr) {
			pHead = new NodeStudent;
			pCur = pHead;
			getline(fileIn, temp, ',');
			pCur->data.No = stringToInt(char(32) + temp);
		}
		else {
			pCur->pNext = new NodeStudent;
			pCur = pCur->pNext;
			getline(fileIn, temp, ',');
			pCur->data.No = stringToInt(temp);
		}
		getline(fileIn, pCur->data.Student_ID, ',');
		getline(fileIn, temp, ',');
		pCur->data.Student_ID = stringToLong(temp);
		getline(fileIn, pCur->data.FirstName, ',');
		getline(fileIn, pCur->data.LastName, ',');
		getline(fileIn, pCur->data.Gender, ',');
	}
	fileIn.close();
}