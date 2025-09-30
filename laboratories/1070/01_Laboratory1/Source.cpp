
//use system libraries
#include <stdio.h>
#include <iostream>


void main()
{
	int vb;
	vb = 10;
	int noOfStudents;
	noOfStudents = 10;
	printf("\n Hello C++");
	std::cout << std::endl << "Hello C++";

	//int values[10];
	//values[10000] = 90;

	//C style
	//int* values = (int*)malloc(10 * sizeof(int));

	//C++ style
	int*values = new int[10];
	//values[10000] = 90;
	values[0] = 90;

}