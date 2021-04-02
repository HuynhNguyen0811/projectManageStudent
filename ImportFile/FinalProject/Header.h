#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct node {
	infoStudent* data;
	node* next;
};

struct infoStudent {
	string no; // Number
	string* id;  // Student ID
	string* lastName, * firstName, gender;
	string* DOB; // day of birth
	string* SID;
	//scoreboard
	string* midterm;
	string* final;
	string* lab;
	string* bonus;

};

struct infoClass {
	string no;
	string* className;
};

struct nodeOfClass {
	infoClass* data;
	listStudent listStu;
	nodeOfClass* next;
};

struct listStudent {
	node* head;
	node* tail;
};

struct listClass {
	nodeOfClass* head, * tail;
};

bool importListStudents(string path, listStudent& lst);
void clearListStudents(listStudent& lst); 
node* createNode(infoStudent* info);