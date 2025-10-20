#include <string>
#include <iostream>
using namespace std;

void printMessage(string msg) {
	cout << endl << "Message:" << msg;
}

void printMessage(char* msg) {
	cout << endl << "Message:" << msg;
}

char* readCourseName() {

	//don't use static array as return
	//they are on the function stack
	char buffer[10000];
	cout << endl << "Give me the course name:";
	cin >> buffer;
	char* response = new char[strlen(buffer) + 1];
	strcpy_s(response, strlen(buffer) + 1, buffer);
	return response;
}

void readCourseName(char* courseName, int maxSize) {
	char buffer[10000];
	cout << endl << "Give me the course name:";
	cin >> buffer;
	if (strlen(buffer) + 1 > maxSize) {
		cout << endl
			<< "New value is too long. Use max "
			<< maxSize - 1;
		return;
	}
	strcpy_s(courseName, maxSize, buffer);
}

string* readStudentNames(int* noStudents) {
	cout << endl << "No of students: ";
	cin >> *noStudents;
	string* names = new string[*noStudents];
	for (int i = 0; i < *noStudents; i++) {
		cout << endl << "Student name:";
		cin >> names[i];
	}
	return names;
}

string* readStudentNamesWithReference(int& noStudents) {
	cout << endl << "No of students: ";
	cin >> noStudents;
	string* names = new string[noStudents];
	for (int i = 0; i < noStudents; i++) {
		cout << endl << "Student name:";
		cin >> names[i];
	}
	return names;
}