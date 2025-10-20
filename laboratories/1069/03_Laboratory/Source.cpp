#include <string>
#include <iostream>
#include "MyLibrary.h"
using namespace std;

//A simple app to manage students grades for a course

void printMessage(string message);
void printArrayOfStrings(string* names, int noElements);
void printArrayOfIntegers(int* values, int noElements);

int main() {

	char courseName[100] = "";
	strcpy_s(courseName, "OOP");

	int noStudents = 0;

	//C style
	//char** names;
	//C++ style
	string* names = nullptr;
	int* grades = nullptr;

	cout << endl << "Course name: " << courseName;
	cout << endl << "No students: " << noStudents;

	printMessage("No of students: ");
	cout << noStudents;

	cout << endl << "New number of students:";
	cin >> noStudents;

	printMessage("No of students: ");
	cout << noStudents;

	//allocate names
	names = new string[noStudents];
	//allocate grades
	grades = new int[noStudents];

	//grades[0] = 10;

	//init grades with 0
	for (int i = 0; i < noStudents; i++) {
		grades[i] = 0;
	}

	printArrayOfStrings(names, noStudents);
	printArrayOfIntegers(grades, noStudents);

}

void printMessage(string message) {
	cout << endl << message;
}

void printArrayOfStrings(string* names, int noElements) {
	printMessage("Names list: ");
	for (int i = 0; i < noElements; i++) {
		cout << " " << names[i];
	}
}

void printArrayOfIntegers(int* values, int noElements) {
	printMessage("Values list: ");
	for (int i = 0; i < noElements; i++) {
		cout << " " << values[0];
	}
}