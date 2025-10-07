#include <iostream>
#include <string>
#include <string.h>

enum StudentType { BACHELOR = 10, MASTER, PHD };

int main() {

	bool isPrototypeApp = true;
	bool hasDebuggingEnabled = false;

	if (hasDebuggingEnabled == true) {
		std::cout << std::endl << "Debugging ON";
	}
	else {
		std::cout << std::endl << "Debugging ON";
	}

	if (isPrototypeApp) {
		std::cout << std::endl << "A prototype";
	}

	StudentType studentType = StudentType::BACHELOR;

	std::cout << std::endl << "Student type:" <<
		studentType;

	// strings
	// defining strings
	// C style
	// static array of chars
	char facultyName[100];
	char universityName[50] = "ASE";

	//facultyName = "CSIE";
	strcpy_s(facultyName, "CSIE");

	std::cout << std::endl << "Faculty: " << facultyName;

	//dynamic arrays of chars
	char* city;
	//city = "Bucharest";
	//allocate space
	std::cout << std::endl << strlen("Bucharest");
	city = new char[strlen("Bucharest") + 1];
	strcpy_s(city, strlen("Bucharest") + 1,"Bucharest");

	std::cout << std::endl << "City: " << city;

	//C++ style
	std::string country;
	country = "Romania";
	country = country + " (RO)";

	std::cout << std::endl << "Country " << country;

	//arrays of numbers
	//static

	float grades[1000];
	int groupNumbers[5] = { 1069,1070,1071,1072,1073 };
	//grades = { 9,10,10 };

	for (int i = 0; i < 1000; i++) {
		grades[i] = 10;
	}

	//init the 10th grade
	grades[9] = 8.5;

	//dynamic arrays
	int* studentsPerGoup;

	//studentsPerGoup = { 23,27,22 };
	// allocate memory
	studentsPerGoup = new int[3];

	studentsPerGoup[0] = 22;
	studentsPerGoup[1] = 23;
	studentsPerGoup[2] = 22;

	for (int i = 0; i < 3; i++) {
		studentsPerGoup[i] = 20;
	}



}

void doSomething() {
	StudentType studentType;
}