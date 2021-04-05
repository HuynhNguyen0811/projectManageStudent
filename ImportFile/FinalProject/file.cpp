#include "Header.h"


void createListStudents(listStudent& lst) {
	lst.head = lst.tail = NULL;
}

void createListClasses(listClass& lst) {
	lst.head = lst.tail = NULL;
}

//
//

node* createNode(infoStudent* info)
{
	node* temp = new node;
	temp->data = info;
	temp->next = NULL;
	return temp;
}

void insertTail(listStudent& lst, infoStudent* info) {
	node* p = createNode(info);
	if (p == NULL) return;
	if (lst.head == NULL && lst.tail == NULL) {
		lst.head = lst.tail = p;
	}
	else {

		lst.tail->next = p;
		lst.tail = p;
	}
}

void insertTail(listClass& lst, infoClass* info) {
	nodeOfClass* p = createNodeOfClass(info, "class.csv");
	if (p == NULL) return;
	if (lst.head == NULL && lst.tail == NULL) {
		lst.head = lst.tail = p;
	}
	else {

		lst.tail->next = p;
		lst.tail = p;
	}
}

nodeOfClass* createNodeOfClass(infoClass* info,string path) {
	nodeOfClass* temp = new nodeOfClass;
	//temp->data = new infoClass;
	temp->data = info;
	importListStudents(path, temp->listStu);
	temp->next = NULL;
	return temp;
}

void sortNo(listStudent lst)
{
	node* cur = lst.head;
	int No = 1;
	while (cur != NULL)
	{
		cur->data->no = to_string(No);
		No++;
		cur = cur->next;
	}
}

void sortNo(listClass lst)
{
	nodeOfClass* cur = lst.head;
	int No = 1;
	while (cur != NULL)
	{
		cur->data->no = to_string(No);
		No++;
		cur = cur->next;
	}
}

//
//

bool importListStudents(string path, listStudent& lst)
{
	createListStudents(lst);
	ifstream file;
	file.open(path);
	if (!file.is_open()) return false;
	else {

		while (!file.eof()) {
			infoStudent* info = new infoStudent;

			info->id = new string;
			info->lastName = new string;
			info->firstName = new string;
			info->DOB = new string;
			info->SID = new string;

			getline(file, info->no, ',');
			getline(file, *(info->id), ',');
			getline(file, *(info->firstName), ',');
			getline(file, *(info->lastName), ',');
			getline(file, info->gender, ',');
			getline(file, *(info->DOB), ',');
			getline(file, *(info->SID), '\n');

			insertTail(lst, info);

		}

		file.close();
		return true;
	}
}

bool importListClasses(string path, listClass& lst) {
	createListClasses(lst);
	ifstream file;
	file.open(path);
	if (!file.is_open())
		return false;
	else {
		while (!file.eof()) {

			infoClass* info = new infoClass;
			info->className = new string;
			info->no = new string;
			getline(file, info->no, ',');
			getline(file, *(info->className), '\n');

			insertTail(lst, info);
		}
		file.close();
		return true;
	}
	sortNo(lst);
}
