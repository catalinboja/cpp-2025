#include <iostream>
#include <string>
#include <string.h>
using namespace std;

// a simple app to manage students grades

void printStringsArrays(string* values, int noElements);
void printIntegersArray(int* values, int noElements);
void initNumbersArray(int* values, int noElements, int defaultValue);
int* createAndInitAnIntegersArray(const int noElements, int defaultValue);


int main() {
	//data
	char faculty[100] = "CSIE";
	std::cout << endl << "Faculty " << faculty;
	strcpy_s(faculty, "ASE - CSIE");
	cout << endl << "Faculty " << faculty;

	int noStudents = 0;
	int* grades = nullptr;

	//C style
	//char** names;
	string* names = nullptr;

	cout << endl << "Number the students:";
	cin >> noStudents;

	//allocate
	names = new string[noStudents];
	grades = new int[noStudents];

	//init the grades array
	initNumbersArray(grades, noStudents, 5);

	names[0] = "John";
	grades[0] = 9;

	printStringsArrays(names, noStudents);
	printIntegersArray(grades, noStudents);

	int staticGrades[100];

	initNumbersArray(staticGrades, noStudents, 5);
	staticGrades[0] = 9;


	printIntegersArray(staticGrades, noStudents);

	//test create and init
	int* newValues = 
		createAndInitAnIntegersArray(noStudents, 0);
	newValues[0] = 99;


	initNumbersArray(staticGrades, noStudents, 5);
	initNumbersArray(staticGrades, noStudents, 5);
	initNumbersArray(staticGrades, noStudents, 5);
	initNumbersArray(staticGrades, noStudents, 5);
	printStringsArrays(names, noStudents);
	printIntegersArray(grades, noStudents);
	printStringsArrays(names, noStudents);
	printIntegersArray(grades, noStudents);
	printStringsArrays(names, noStudents);
	printIntegersArray(grades, noStudents);


	printIntegersArray(newValues, noStudents);
	newValues[1] = 100;
	printIntegersArray(newValues, noStudents);

}

void printStringsArrays(string* values, int noElements) {
	cout << endl << "The values are: ";
	for (int i = 0; i < noElements; i += 1) {
		cout << " " << values[i];
	}
}

void printIntegersArray(int* values, int noElements) {
	cout << endl << "Numeric values: ";
	for (int i = 0; i < noElements; i++) {
		cout << " " << values[i];
	}
}

void initNumbersArray(int* values,
	int noElements, int defaultValue) {
	for (int i = 0; i < noElements; i++) {
		values[i] = defaultValue;
	}
}

int* createAndInitAnIntegersArray(
	const int noElements, int defaultValue) {
	int newArray[1000];
	for (int i = 0; i < noElements; i++) {
		newArray[i] = defaultValue;
	}
	return newArray;
}


