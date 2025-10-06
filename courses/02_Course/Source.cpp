#include <iostream>
#include <string>
#include <string.h>
#include "Math.h"

enum StudentType {BACHELOR = 10, MASTER, PHD = 30};

int main() {

	std::cout << std::endl << "Hello";
	add(2, 3);

	int values[100];
	int index = 10;
	values[index] = 300;

	unsigned int noStudentsWithScholarship;
	int temperature = -23;
	float productPrice = 23.6;
	double averageTemp = 21.666788;

	char smallNumber = 23;
	char aLetter = 97;  //'a'
	//char bLetter = "b";

	bool isMasterStudent = true;
	bool hasScholarship = false;

	//int studentType = 1;

	//std::string studentType = "bachelor";
	//studentType = "Bachelor";

	StudentType studentType = 
		StudentType::BACHELOR;

	//arrays
	//static arrays
	int values[5] = {10,20,30,40,50};
	//values = { 10,20,30,40,50 };

	char name[100] = "John";
	//name = "Alice";


	//dynamic arrays
	int* values2;



	noStudentsWithScholarship = 10;


	return 0;
}