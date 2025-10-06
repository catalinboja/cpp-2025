#include <iostream>
#include <string>
#include <string.h>

enum StudentType { BACHELOR = 10, MASTER = 20, PHD };

int main() {

	//data types
	char aSingleChar;
	aSingleChar = 'a';
	//aSingleChar = "a";
	
	std::cout << std::endl << "A single char: " 
		<< aSingleChar;
	
	aSingleChar = 64;

	std::cout << std::endl << "A single char: " 
		<< aSingleChar;

	int noStudents = 10;
	unsigned int noClasses = 23;
	float average = 9.8;
	double passingRate = 73.2226;
	bool isValidated = true;
	bool hasScholarship = false;

	StudentType studentType = StudentType::MASTER;
	studentType = StudentType::BACHELOR;

	std::cout << std::endl << "The student type is :"
		<< studentType;

	//arrays
	//static 
	float grades[100];
	grades[0] = 9;
	//off by one error
	//grades[100] = 10;
	grades[99] = 10;

	//dynamic
	float* multipleGrades;
	//step 1 allocate memory
	unsigned int noGrades;

	std::cout << std::endl << 
		"Give me the number of grades:";
	std::cin >> noGrades;

	// error because the array is not created
	// multipleGrades[0] = 10;

	multipleGrades = new float[noGrades];

	//init the array values
	for (int i = 0; i < noGrades; i++) {
		multipleGrades[i] = 0;
	}

	multipleGrades[0] = 10;


	//float otheGrades[noGrades];

	//char arrays
	//static
	char facultyName[100];
	// a bad joke
	//facultyName[0] = 'C';
	//facultyName[1] = 'y';

	//facultyName = "CSIE";
	strcpy_s(facultyName, "CSIE");


	//dynamic
	char* universityName;
	//allocate memory
	universityName = new char[strlen("ASE") + 1];
	strcpy_s(
		universityName, strlen("ASE") + 1, "ASE");




	return 0;
}
