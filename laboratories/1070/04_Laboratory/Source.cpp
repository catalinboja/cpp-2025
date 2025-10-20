#include <iostream>
#include <string>
#include <string.h>
#include "StudentService.h"
using namespace std;


int main() {
	char courseName[100] = "";
	int noStudents = 0;
	string* names = nullptr;
	int* grades = nullptr;

	printMessage("Student App");
	printMessage(courseName);

	char* newCourseName = readCourseName();
	strcpy_s(courseName, newCourseName);
	//remove the new course name from Heap
	delete[] newCourseName;

	readCourseName(courseName, 100);

	printMessage(courseName);

	names = readStudentNames(&noStudents);
	names = readStudentNamesWithReference(noStudents);

}

