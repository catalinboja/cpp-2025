#include <stdio.h>
#include <iostream>
#include <string>

int main() {
	int noOfStudents = 0;
	noOfStudents = 10;
	std::string name = "John";
	printf("\n Hello C++"); //C style
	std::cout << std::endl << "Hello C++"; //C++ style
	
	int* values = new int[10];
	//values[10000] = 10; //runtime error
	values[1] = 10;

	return 0;
}